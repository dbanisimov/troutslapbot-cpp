# troutslapbot-cpp
Simpe Telegram bot that allows you to slap someone around a bit with a wet trout using modern C++

# Build
## Prerequisites
The bot uses [cpprest](https://github.com/Microsoft/cpprestsdk) library. This library is included as
a git submodule and needed to be updated after the initial repository checkout:
```
git submodule init
git submodule update
```
The cpprest library depends on Boost libraries, so you have to install them first. 
On most of the Linux distributions this should be straightforward.
## Make
First, run cmake:
```
cmake .
```
Then build using make:
```
make
```
## Note
By default static version of cpprest with static linking to Boost is built. 
If you want to change this behavior modify the root CMakeLists file. You may
have to clear the cmake cache first to apply this change for rebuild.
# Usage
```
slap <bot_token>
```
Handy option on Linux systems:
```
echo <bot_token> > bot_token
cat bot_token | xargs ./slap
```
