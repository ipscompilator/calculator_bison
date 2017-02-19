#pragma once
#include "Parser.hpp"
#include "location.hh"

namespace calc {

    class Scanner
    {
    public:
        Scanner(std::istream &inStream);
        ~Scanner();
        Parser::symbol_type lex();

    private:
        void Scanner::skipSpaces();
		double Scanner::parseDouble();

		std::unique_ptr<location> m_location;
        std::istream &m_inStream;
    };
    
        
}