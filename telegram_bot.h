/**
 * Author: Denis Anisimov 2015
 * 
 * Telegram bot
 * 
 */

#ifndef TELEGRAM_BOT_H_
#define	TELEGRAM_BOT_H_

#include <string>
#include <cpprest/json.h>
#include <cpprest/http_client.h>

class TelegramBot {
public:
  TelegramBot(std::string token);
  void Run();
protected:
  virtual void ProcessMessage(web::json::object message) = 0;
  web::json::value MakeRequest(std::string query);
private:
  void ProcessUpdate(web::json::object update);
  void TestMe();
private:
  const std::string token_;
  const std::string bot_url_;
  int64_t last_update_id_ {0};
};

#endif	/* TELEGRAM_BOT_HPP */

