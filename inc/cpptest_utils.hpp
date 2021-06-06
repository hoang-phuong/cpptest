#pragma once

#include <string>
#include <vector>

namespace phuong
{
    namespace cpptest
    {
        class Utilities
        {
          public:
            static Utilities& getInstance();

            std::string joinString(std::vector<std::string> const& listOfStrings, std::string delimiter);

          private:
            Utilities()                 = default;
            ~Utilities()                = default;
            Utilities(Utilities const&) = delete;
            Utilities(Utilities&&)      = delete;
            Utilities& operator=(Utilities const&) = delete;
            Utilities& operator=(Utilities&&) = delete;
        };
    } // namespace cpptest
} // namespace phuong
