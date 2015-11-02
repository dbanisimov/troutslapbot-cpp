/**
 * Author: Denis Anisimov 2015
 * 
 * Implementation of telegram bot
 * 
 */

#include "telegram_bot.h"

#include <chrono>
#include <thread>

#include <cpprest/http_client.h>

constexpr char kTelegramEndpoint[] = "https://api.telegram.org/bot";

TelegramBot::TelegramBot(std::string token)
: token_(token),
  bot_url_(kTelegramEndpoint + token) {}

void TelegramBot::Run() {
  if (!TestMe()) {
    return;
  }

  using namespace std::literals;
  while((true)) {
    std::this_thread::sleep_for(2s);
  }
}

bool TelegramBot::TestMe() {
  bool result{false};
  web::http::client::http_client client(U(bot_url_));
  client.request(web::http::methods::GET, web::http::uri_builder(U("/getMe")).to_string())
  .then([&result](web::http::http_response response) {
    result = (response.status_code() == 200);
  })
  .wait();
  return result;
}
