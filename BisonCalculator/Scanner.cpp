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
            std::cout << "  Return EOL" << std::endl;
            m_inStream.get();
            return Parser::make_EOL();
        }

        if (std::isdigit(m_inStream.peek()))
        {
            double val(0);
            m_inStream >> val;
            std::cout << "  Return double " << val << std::endl;
            return Parser::make_DOUBLE(val);
        }

        char currentChar;
        if (m_inStream >> currentChar)
        {
            if (currentChar == '+')
            {
                std::cout << "  Return +" << std::endl; 
                return Parser::make_PLUS();
            }
            if (currentChar == '-')
            {
                std::cout << "  Return -" << std::endl; 
                return Parser::make_MINUS();
            }
            if (currentChar == '*')
            {
                std::cout << "  Return *" << std::endl; 
                return Parser::make_MULTIPLY();
            }
            if (currentChar == '/')
            {
                std::cout << "  Return /" << std::endl; 
                return Parser::make_DIVIDE();
            }
            if (currentChar == '(')
            {
                std::cout << "  Return (" << std::endl; 
                return Parser::make_LEFT_P();
            }
            if (currentChar == ')')
            {
                std::cout << "  Return )" << std::endl;
                return Parser::make_RIGHT_P();
            }
            
            throw Parser::syntax_error("Unexpected symbol.");
        } 
        else 
        {
            std::cout << "  Return EOF" << std::endl;
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