/**
 * Author: Denis Anisimov 2015
 * 
 * Trout slapping bot class
 * 
 */

#ifndef TROUT_SLAP_BOT_H_
#define	TROUT_SLAP_BOT_H_

#include "telegram_bot.h"

class TroutSlapBot : public TelegramBot {
public:
  using TelegramBot::TelegramBot;
  virtual void ProcessMessage(web::json::object message) override;
};

#endif	/* TROUT_SLAP_BOT_H_ */
