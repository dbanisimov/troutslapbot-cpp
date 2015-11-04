/**
 * Author: Denis Anisimov 2015
 * 
 * Implementation of telegram bot
 * 
 */

#include "telegram_bot.h"

#include <chrono>
#include <iostream>
#include <thread>

#include <cpprest/http_client.h>

#include "telegram_exceptions.h"

constexpr char kTelegramEndpoint[] = "https://api.telegram.org/bot";

TelegramBot::TelegramBot(std::string token)
: token_(token),
  bot_url_(kTelegramEndpoint + token) {}

void TelegramBot::Run() {
  std::cout << "Bot started" << std::endl;

  try {
    TestMe();
  } catch (...) {
    std::cout << "Bot self-test using getMe method failed." << std::endl;
    return;
  }
  
  std::cout << "Bot self-test passed" << std::endl;

  using namespace std::literals;
  while((true)) {
    try {
      auto updates = MakeRequest(
        web::http::uri_builder("/getUpdates")
        .append_query("offset", last_update_id_ + 1)
        .to_string()
      ).as_array();
      for (auto& update : updates) {
        last_update_id_ = update.as_object().at("update_id").as_integer();
        ProcessMessage(update.as_object().at("message").as_object());
      }
    } catch (UnsuccessfulRequest &ex) {
      std::cout << "Cannot get updates. Code: " << ex.status_code_
        << " Description: " << ex.description_ << std::endl;
    } catch (std::runtime_error &ex) {
      std::cout << "Cannot get updates. " << ex.what() << std::endl;
    } catch (web::json::json_exception& ex) {
      std::cout << "Cannot get updates. Cannot process json: " << ex.what() << std::endl;  
    } catch (...) {
      std::cout << "Cannot get updates. Unknown exception." << std::endl;
    }
    std::this_thread::sleep_for(2s);
  }
}

web::json::value TelegramBot::MakeRequest(std::string query) {
  web::http::client::http_client client(U(bot_url_));
  web::http::status_code response_code;
  auto response_body = std::make_shared<concurrency::streams::stringstreambuf>();
  client.request(web::http::methods::GET, query)
  .then([&response_code, &response_body](web::http::http_response response) -> pplx::task<size_t> {
     response_code = response.status_code();
     return response.body().read_to_end(*response_body);
  })
  .wait();
  
  auto response_json = web::json::value::parse(response_body->collection());
  
  bool response_ok = response_json.as_object().at("ok").as_bool();
  
  if (response_code != 200 || !response_ok) {
    std::string description = "";
    auto it = response_json.as_object().find("description");
    if (it != response_json.as_object().end()) {
      description = it->second.as_string();
    }
    throw UnsuccessfulRequest(response_code, description);
  }
  
  return response_json.as_object().at("result");
}

void TelegramBot::SendMessage(int64_t chat_id, std::string text) {
  MakeRequest(
    web::http::uri_builder("/sendMessage")
    .append_query("chat_id", chat_id)
    .append_query("text", text)
    .to_string()
  );
}

void TelegramBot::TestMe() {
  MakeRequest("/getMe");
}
