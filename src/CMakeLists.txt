set(SOURCES
  slap.cc
  telegram_bot.cc
  trout_slap_bot.cc
)

set(HEADERS
  telegram_bot.h
  telegram_exceptions.h
  trout_slap_bot.h
)

add_executable(slap ${SOURCES} ${HEADERS})
target_link_libraries(slap cpprest)
