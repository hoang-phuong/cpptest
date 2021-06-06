#include "cpptest_logger_console.hpp"
#include "cpptest_utils.hpp"
#include <cstdint>
#include <iostream>
#include <stdexcept>

using namespace phuong::cpptest;

ConsoleLogger& ConsoleLogger::getInstance()
{
    static ConsoleLogger instance;

    return instance;
}

std::string ConsoleLogger::formatPlainMessage(std::string message, std::vector<FontEffect> const& fontEffects)
{
    std::string output = kEscSeqPrefix;

    if ( fontEffects.size() != 0 )
    {
        std::vector<std::string> fontEffectsString;
        for ( FontEffect effect : fontEffects )
        {
            fontEffectsString.push_back(std::to_string(static_cast<int>(effect)));
        }
        output += Utilities::getInstance().joinString(std::move(fontEffectsString), kEscCodeDelimiter);
        output += kEscSeqEnd;
    }
    output += message;
    output += kEscSeqReset;

    return output;
}

void ConsoleLogger::info(std::string message)
{
    if ( this->canShowLog(Level::kInfo) )
    {
        std::cout << formatPlainMessage(std::move(message), infoFont);
    }
}

void ConsoleLogger::debug(std::string message)
{
    if ( this->canShowLog(Level::kDebug) )
    {
        std::cout << formatPlainMessage(std::move(message), debugFont);
    }
}

void ConsoleLogger::warn(std::string message)
{
    if ( this->canShowLog(Level::kWarning) )
    {
        std::cout << formatPlainMessage(std::move(message), warnFont);
    }
}

void ConsoleLogger::error(std::string message)
{
    if ( this->canShowLog(Level::kError) )
    {
        std::cout << formatPlainMessage(std::move(message), errorFont);
    }
}
