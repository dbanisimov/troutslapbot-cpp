/**
 * Author: Denis Anisimov 2015
 * 
 * Implementation of telegram bot
 * 
 */

#include "telegram_bot.h"

#include <chrono>
#include <thread>

TelegramBot::TelegramBot(std::string token) : token_(token) {
  // Do nothing
}

void TelegramBot::Run() {
  using namespace std::literals;
  while((true)) {
    std::this_thread::sleep_for(2s);
  }
}


