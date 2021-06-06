#include "cpptest_logger_abstract.hpp"

using namespace phuong::cpptest;

void AbstractLogger::log(Level level, std::string message)
{
    if ( !this->canShowLog(level) )
    {
        return;
    }

    switch ( level )
    {
    case Level::kDebug:
        this->debug(std::move(message));
        break;
    case Level::kInfo:
        this->info(std::move(message));
        break;
    case Level::kWarning:
        this->warn(std::move(message));
        break;
    case Level::kError:
        this->error(std::move(message));
        break;
    }
}

void AbstractLogger::enableDebugLogging()
{
    this->minimumLoggingLevel = Level::kDebug;
}

void AbstractLogger::disableDebugLogging()
{
    this->minimumLoggingLevel = Level::kInfo;
}

bool AbstractLogger::canShowLog(Level level)
{
    return (static_cast<int>(level) >= static_cast<int>(this->minimumLoggingLevel));
}
