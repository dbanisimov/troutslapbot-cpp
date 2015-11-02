/**
 * Author: Denis Anisimov 2015
 * 
 * Slap bot written in C++
 * 
 */

#include <iostream>

#include "trout_slap_bot.h"

int main(int argc, char** argv) {
  if (argc < 2) {
    std::cout << "Usage: slap <bot_token>" << std::endl;
    exit(1);
  }

  std::string token(argv[1]);
  TroutSlapBot bot(token);

  bot.Run();

  return 0;
}