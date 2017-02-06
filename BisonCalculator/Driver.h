#pragma once
#include <string>
#include <iostream>
#include <memory>
#include "Scanner.h"

namespace yy {

    class Driver
    {
    public:
        Driver();
        ~Driver();

        double getResultValue() const;
        void setResultValue(double resultValue);

        Scanner &getScanner() const;

        bool parseStream(std::istream &inStream);
        bool parseString(const std::string &inString);

        void error(const std::string &msg);

    private:
        double m_resultValue;
        std::unique_ptr<Scanner> m_scanner;
    };

}