#include "stdafx.h"
#include <cctype>
#include "Scanner.h"

using namespace std;

namespace calc {

    Scanner::Scanner(std::istream &inStream)
        : m_inStream(inStream)
    {
    }

    Scanner::~Scanner()
    {
    }

	Parser::token_type Scanner::lex(Parser::semantic_type *val, Parser::location_type *loc)
    {
		loc->step();
		if (m_inStream.peek() == ' ')
        {
            skipSpaces(loc);
        }

        if (m_inStream.peek() == '\n')
        {
			loc->lines(1);
			m_inStream.get();
			
			return Parser::token_type::TOK_EOL;
        }

        if (std::isdigit(m_inStream.peek()))
        {
			val->doubleVal = parseDouble(loc);
			return Parser::token_type::TOK_DOUBLE;
        }

        char currentChar;
        if (m_inStream >> currentChar)
        {
            if (currentChar == '+')
            {
				loc->columns(1);
				return Parser::token_type::TOK_PLUS;
            }
            if (currentChar == '-')
            {
				loc->columns(1);
				return Parser::token_type::TOK_MINUS;
            }
            if (currentChar == '*')
            {
				loc->columns(1);
				return Parser::token_type::TOK_MULTIPLY;
            }
            if (currentChar == '/')
            {
				loc->columns(1);
				return Parser::token_type::TOK_DIVIDE;
            }
            if (currentChar == '(')
            {
				loc->columns(1);
				return Parser::token_type::TOK_LEFT_P;
            }
            if (currentChar == ')')
            {
				loc->columns(1);
				return Parser::token_type::TOK_RIGHT_P;
            }
        } 
        else 
        {
			return Parser::token_type::TOK_END;
        }
        
    }

	void Scanner::skipSpaces(Parser::location_type *loc)
    {
        while (m_inStream.get() == ' ')
        {
			loc->columns(1);
        }
		loc->step();
        m_inStream.unget();
    }

	double Scanner::parseDouble(Parser::location_type *loc)
	{
		double value = 0;
		char currentChar;

		while (m_inStream.good())
		{
			currentChar = m_inStream.get();
			if (isdigit(currentChar))
			{
				loc->columns(1);
				const int digit = currentChar - '0';
				value = value * 10.0f + double(digit);
			}
			else
			{
				break;
			}
		}

		if (currentChar != '.') {
			m_inStream.unget();
			return value;
		}

		loc->columns(1); // consume .

		double factor = 1;
		while (m_inStream.good())
		{
			currentChar = m_inStream.get();
			if (isdigit(currentChar))
			{
				loc->columns(1);
				const int digit = currentChar - '0';
				factor *= 0.1;
				value += factor * double(digit);
			}
			else
			{
				break;
			}
		}
		m_inStream.unget();

		return value;
	}

}