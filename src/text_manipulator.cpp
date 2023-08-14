#include <string>
#include <vector>
#include <text_manipulator.h>

// Make a string composed of char c repeated n times
std::string TextManipulator::repeat_character(char c, int n)
{
    std::string result = "";
    for (int i = 0; i < n; i++)
    {
        result += c;
    }
    return result;
}