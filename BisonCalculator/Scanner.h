#pragma once
#include "Parser.hpp"

namespace calc {

    class Scanner
    {
    public:
        Scanner(std::istream &inStream);
        ~Scanner();
        Parser::symbol_type lex();

    private:
        void Scanner::skipSpaces();
                
        std::istream &m_inStream;
    };
    
        
}