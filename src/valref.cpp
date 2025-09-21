#include "valref.hpp"

void inc_by_value(int x)
{
    x = x + 1;
}

void inc_by_ref(int &x)
{
    ++x;
}

void append_value(std::string s)
{
    s += "!";
}

void append_ref(std::string &s)
{
    s += "!";
}
