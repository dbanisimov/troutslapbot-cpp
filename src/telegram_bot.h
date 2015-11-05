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
  /**
   * Create a bot identified by token
   */
  TelegramBot(std::string token);
  /**
   * Run the bot in a long polling mode
   */
  void Run();
  
protected:
  /**
   * Process the incoming message. 
   * A concrete bot should implement this method.
   */
  virtual void ProcessMessage(web::json::object message) = 0;
  /**
   * Make a request using a query string.
   * Returns a JSON response. Throws UnsuccessfulRequest on API usage error,
   * web::json::json_exception on bad JSON response.
   */
  web::json::value MakeRequest(std::string query);
  /**
   * Send a text message to a specified chat.
   */
  void SendMessage(int64_t chat_id, std::string text);
  
private:
  /**
   * Bot self-test using getMe bot API method
   */
  void TestMe();
  
private:
  const std::string token_;
  const std::string bot_url_;
  int64_t last_update_id_ {0};
};

#endif	/* TELEGRAM_BOT_HPP */

