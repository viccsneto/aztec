#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <GameEngine.h>
#include <Config.h>
#include <string>
#include <locale>
#include <lua.hpp>

std::string main_file(MAIN_LUA_FILE);

std::string convert_lowercase(std::string str)
{
  std::locale loc;
  for (int i = 0; i < str.size(); i++)
    str[i] = std::tolower(str[i], loc);
  return str;
}

void process_arguments(int argc, char *argv[])
{

  for (int i = 0; i < argc; i++) {
    GameEngine::getInstance()->Arguments->add(("argv[" + std::to_string(i) + "]").c_str(), argv[i]);
    if (i > 0) {
      std::string str_arg = convert_lowercase(argv[i]);
      if (str_arg == "/debug") {
        Config::DEBUG_DRAW = true;
      }
      else if (str_arg.find(".lua", str_arg.size() - 4) != std::string::npos) {
        main_file = std::string(argv[i]);
      }
    }
  }
}

int main(int argc, char *argv[])
{

  if (GameEngine::Initialize()) {
    process_arguments(argc, argv);
    if (luaL_dostring(GameEngine::LUA_STATE, "__Aztec__InitializeCommonComponents()") != 0 || luaL_dofile(GameEngine::LUA_STATE, main_file.c_str()) != 0) {
      GameEngine::getInstance()->registerError("LUA: %s - <%s [%d]>", lua_tostring(GameEngine::LUA_STATE, -1), __FILE__, __LINE__);
      return 1;
    }

    GameEngine::freeInstance();
  }

  return 0;
}