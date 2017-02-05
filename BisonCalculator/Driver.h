#pragma once
#include <string>
#include <iostream>
#include "Scanner.h"

namespace yy {

    class Driver
    {
    public:
        Driver();
        ~Driver();

        Scanner *scanner;
        double resultValue;

        bool parseStream(std::istream &inStream);
        bool parseString(const std::string &inString);

        void error(const std::string &msg);
    };

}