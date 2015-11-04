/**
 * Author: Denis Anisimov 2015
 * 
 * Telegram bot exceptions
 * 
 */

#ifndef TELEGRAM_EXCEPTIONS_H_
#define	TELEGRAM_EXCEPTIONS_H_

#include <string>
#include <cpprest/http_client.h>

class UnsuccessfulRequest : public std::exception {
public:
  web::http::status_code status_code_;
  std::string description_;
public:
  UnsuccessfulRequest(web::http::status_code code, std::string desc) 
    : status_code_(code), description_(desc) {};
};

#endif	/* TELEGRAM_EXCEPTIONS_H_ */

