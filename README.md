# troutslapbot-cpp
Simpe Telegram bot that allows you to slap someone around a bit with a wet trout using modern C++

# Build
## Prerequisites
The bot uses [cpprest](https://github.com/Microsoft/cpprestsdk) library. You have to download and build it first.

## Make
First, run cmake with paths to your cpprest installation:
```
cmake . -DCPPREST_INCLUDES="/path/to/Release/include/" \
        -DCPPREST_LIB_DIR="/path/to/Release/build.release/Binaries"
```
Then build it using make
```
make
```
# Usage
```
slap <bot token>
```
