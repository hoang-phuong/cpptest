#include "cpptest.hpp"
#include <iostream>

#include "cpptest_logger_console.hpp"

int main(void)
{
    phuong::cpptest::ConsoleLogger::getInstance().disableDebugLogging();
    phuong::cpptest::ConsoleLogger::getInstance().info("Huynh Doan Nhu An");
    phuong::cpptest::ConsoleLogger::getInstance().debug("Just some debug information");
    phuong::cpptest::ConsoleLogger::getInstance().warn("This a warning");
    phuong::cpptest::ConsoleLogger::getInstance().error("This is error");
    phuong::cpptest::ConsoleLogger::getInstance().log(phuong::cpptest::AbstractLogger::Level::kError, "Hello another error");
    return 0;
}
