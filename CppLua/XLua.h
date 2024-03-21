#pragma once

#include <sol/sol.hpp>
#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;


class XLua {
private:
    sol::state lua;

    void loadScript(const std::string& path) {
        lua.script_file(path);
    }

public:
    XLua() {
        lua.open_libraries(sol::lib::base, sol::lib::package, sol::lib::math, sol::lib::os);

        //Register Functions C++ in Lua
        lua.set_function("printMessage",            &XLua::SCRIPT_PrintMessage, this);
        lua.set_function("addNumbers",              &XLua::SCRIPT_AddNumbers, this);
        lua.set_function("isNumberEven",            &XLua::SCRIPT_IsNumberEven, this);
        lua.set_function("getAppName",              &XLua::SCRIPT_GetAppName, this);
        lua.set_function("generateRandomNumber",    &XLua::SCRIPT_GenerateRandomNumber, this);
    }

    void reloadScripts();

    template<typename... Args>
    void callFunction(const std::string& name, Args... args);

private:

    //C++ Functions
    void    SCRIPT_PrintMessage(const std::string& message);
    int     SCRIPT_AddNumbers(int a, int b);
    bool    SCRIPT_IsNumberEven(int number);
    std::string SCRIPT_GetAppName();
    int SCRIPT_GenerateRandomNumber(int min, int max);


};




template<typename ...Args>
void XLua::callFunction(const std::string& name, Args ...args) {
    try {
        lua[name](args...);
    }
    catch (const sol::error& e) {
        std::cerr << "Wyj¹tek sol::error: " << e.what() << std::endl;
    }
}
