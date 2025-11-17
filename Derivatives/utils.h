#pragma once
#include <string>
#include <sstream>
#include <iomanip>
#include <iostream>

class Utils
{
public:
    static bool is_number(const std::string &s);
    static bool is_variable(const std::string &s);
    static std::string double_to_string(double);
};
