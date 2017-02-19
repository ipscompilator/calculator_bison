#pragma once
#include <string>
#include <iostream>
#include <memory>
#include "Scanner.h"
#include "CalcNode.h"

namespace calc
{

    class Driver
    {
    public:
        Driver();
        ~Driver();

        double getResultValue() const;

        Scanner & getScanner() const;

        CalcNode & getCalcNode() const;
		void setCalcNode(std::unique_ptr<CalcNode> && calcNode);

        bool parseStream(std::istream & inStream);
        bool parseString(const std::string & inString);

		void error(const std::string & msg, const location & location);

        void printResult();

    private:
        std::unique_ptr<Scanner> m_scanner;
        std::unique_ptr<CalcNode> m_calcNode;
    };

}