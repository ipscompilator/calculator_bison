#include "stdafx.h"
#include <cctype>
#include "Scanner.h"


namespace yy {

    Scanner::Scanner(std::istream &inStream)
        : m_inStream(inStream)
    {
    }

    Scanner::~Scanner()
    {
    }

    Parser::symbol_type Scanner::lex()
    {
        if (m_inStream.peek() == ' ')
        {
            skipSpaces();
        }

        if (m_inStream.peek() == '\n')
        {
            m_inStream.get();
            return Parser::make_EOL();
        }

        if (std::isdigit(m_inStream.peek()))
        {
            double val(0);
            m_inStream >> val;
            return Parser::make_DOUBLE(val);
        }

        char currentChar;
        if (m_inStream >> currentChar)
        {
            if (currentChar == '+')
            {
                return Parser::make_PLUS();
            }
            if (currentChar == '-')
            {
                return Parser::make_MINUS();
            }
            if (currentChar == '*')
            {
                return Parser::make_MULTIPLY();
            }
            if (currentChar == '/')
            {
                return Parser::make_DIVIDE();
            }
            if (currentChar == '(')
            {
                return Parser::make_LEFT_P();
            }
            if (currentChar == ')')
            {
                return Parser::make_RIGHT_P();
            }
            
            throw Parser::syntax_error("Unexpected symbol.");
        } 
        else 
        {
            return Parser::make_END();
        }
        
    }

    void Scanner::skipSpaces()
    {
        while (m_inStream.get() == ' ')
        {
        }
        m_inStream.unget();
    }

}