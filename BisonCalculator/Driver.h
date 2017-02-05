#pragma once

#include <string>
#include <iostream>

namespace yy {

    class Driver
    {
    public:
        Driver();
        ~Driver();

        bool parseStream(std::istream &inStream);
        bool parseString(const std::string &inString);
    };

}