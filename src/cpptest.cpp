#include "cpptest.hpp"

using namespace phuong::cpptest;

CppTest& CppTest::getInstance()
{
    static CppTest instance;

    return instance;
}
