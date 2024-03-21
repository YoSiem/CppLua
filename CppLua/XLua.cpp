#include "XLua.h"
#include <random>

void XLua::reloadScripts() {
    for (const auto& entry : fs::directory_iterator("Scripts")) {
        loadScript(entry.path().string());
    }
}

void XLua::SCRIPT_PrintMessage(const std::string& message)
{
    std::cout << message << std::endl;
}

int XLua::SCRIPT_AddNumbers(int a, int b)
{
    return a + b;
}

bool XLua::SCRIPT_IsNumberEven(int number)
{
    return (number % 2) == 0;
}

std::string XLua::SCRIPT_GetAppName()
{
    return "CppLua Integration App";
}

int XLua::SCRIPT_GenerateRandomNumber(int min, int max)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(min, max);
    return distr(gen);
}
