#include "cpptest_utils.hpp"

using namespace phuong::cpptest;

Utilities& Utilities::getInstance()
{
    static Utilities instance;
    return instance;
}

std::string Utilities::joinString(std::vector<std::string> const& listOfStrings, std::string delimiter)
{
    std::string output = "";

    if (listOfStrings.size() != 0)
    {
        output = listOfStrings.at(0);

        int i;
        for (i = 0; i < listOfStrings.size(); i++)
        {
            output += (delimiter + listOfStrings.at(i));
        }
    }

    return output;
}
