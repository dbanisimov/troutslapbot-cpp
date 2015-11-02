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

class TelegramBot {
public:
  TelegramBot(std::string token);
  virtual void ProcessMessage(web::json::object message) = 0;
private:
  void ProcessUpdate(web::json::object update);
private:
  const std::string token_;
};

#endif	/* TELEGRAM_BOT_HPP */

