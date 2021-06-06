#pragma once

#include <string>

namespace phuong
{
    namespace cpptest
    {
        class AbstractLogger
        {
          public:
            enum class Level
            {
                kDebug = 0,
                kInfo,
                kWarning,
                kError
            };

            virtual void info(std::string message)  = 0;
            virtual void debug(std::string message) = 0;
            virtual void warn(std::string message)  = 0;
            virtual void error(std::string message) = 0;
            virtual void log(Level level, std::string message);

            void         enableDebugLogging();
            void         disableDebugLogging();
            bool         canShowLog(Level level);

          private:
            Level minimumLoggingLevel = Level::kInfo;
        };
    } // namespace cpptest
} // namespace phuong
