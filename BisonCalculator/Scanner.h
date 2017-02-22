#pragma once
#include "Parser.hpp"
#include "location.hh"

namespace calc {

    class Scanner
    {
    public:
        Scanner(std::istream &inStream);
        ~Scanner();
		Parser::token_type lex(Parser::semantic_type *val, Parser::location_type *loc);

    private:
		void Scanner::skipSpaces(Parser::location_type *loc);
		double Scanner::parseDouble(Parser::location_type *loc);
        std::istream &m_inStream;
    };

}