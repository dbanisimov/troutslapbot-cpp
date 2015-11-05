/**
 * Author: Denis Anisimov 2015
 * 
 * Implementation of trout slapping bot
 * 
 */

#include "trout_slap_bot.h"

#include <string>
#include <cpprest/uri_builder.h>

constexpr char kSlapCommand[] = "/slap";   
constexpr size_t kSlapCommandLen = strlen(kSlapCommand);

void TroutSlapBot::ProcessMessage(web::json::object message) {
  auto chat_id = message.at("chat").at("id").as_integer();
  auto it = message.find("text");
  if (it == message.end())  {
    // not a text message
    return;
  }  
  auto text = it->second.as_string();
  if ((text.size() < kSlapCommandLen)
      || (text.substr(0, kSlapCommandLen) != kSlapCommand)) {
    // the text doesn't have slap command or username 
    return;
  }
  
  std::string username;
  if (text.size() == kSlapCommandLen) {
    username = "himself";
  } else {
    username = text.substr(kSlapCommandLen + 1, text.find(' ', kSlapCommandLen + 1));
    if (username.size() > 0 && username[0] != '@') {
      username = '@' + username;
    }
  }
  std::string user_from;
  if (message.at("from").as_object().find("username") != message.at("from").as_object().end()) {
    user_from = '@' + message.at("from").at("username").as_string();
  } else {
    user_from = message.at("from").at("first_name").as_string();
  }
  auto msg_text = user_from + " slaps " + username + " around a bit with a large trout";
  SendMessage(chat_id, msg_text);
}
