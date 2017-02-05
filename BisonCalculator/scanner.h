#pragma once

#include "Parser.hpp"

namespace yy {

    class Scanner
    {
    public:
        Scanner(std::istream &inStream);
        ~Scanner();
        yy::Parser::symbol_type lex();
    private:
        void yy::Scanner::skipSpaces();

        std::istream &m_inStream;
    };

}