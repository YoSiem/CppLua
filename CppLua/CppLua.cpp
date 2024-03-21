#include "XLua.h"
#include <iostream>


int main() {
    XLua xLua;

    xLua.reloadScripts();
    xLua.callFunction("greeting", "YoSiem", "Patryk");
    xLua.callFunction("cppPrint", "Hello from C++ in Lua :D");
    xLua.callFunction("add_test", 10, 55);
    xLua.callFunction("even_test", 5);
    xLua.callFunction("app_name_test");
    xLua.callFunction("random_test", 1, 10000);
    xLua.callFunction("OnMonsterDead");

    return 0;
}