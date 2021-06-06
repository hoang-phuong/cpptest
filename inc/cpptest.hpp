#pragma once

#include "cpptest_logger_console.hpp"
#include "cpptest_testcase.hpp"

#define CPPTEST (phuong::cpptest::CppTest::getInstance())
namespace phuong
{
    namespace cpptest
    {
        class CppTest
        {
          public:
            static CppTest& getInstance();
            void            startTest(std::string name, std::string description);

          private:
            CppTest()  = default;
            ~CppTest() = default;
            /* Remove copy constructor and copy constructor */
            CppTest(CppTest const&) = delete;
            CppTest(CppTest&&)      = delete;
            CppTest& operator=(CppTest const&) = delete;
            CppTest& operator=(CppTest&&) = delete;
        };
    } // namespace cpptest
} // namespace phuong
