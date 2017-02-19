#include "stdafx.h"
#include <cctype>
#include "Scanner.h"

using namespace std;

namespace calc {

    Scanner::Scanner(std::istream &inStream)
        : m_inStream(inStream)
    {
		m_location = make_unique<location>();
    }

    Scanner::~Scanner()
    {
    }

    Parser::symbol_type Scanner::lex()
    {
		m_location->step();
		if (m_inStream.peek() == ' ')
        {
            skipSpaces();
        }

        if (m_inStream.peek() == '\n')
        {
			m_location->lines(1);
			m_inStream.get();
			
			return Parser::make_EOL(*m_location);
        }

        if (std::isdigit(m_inStream.peek()))
        {
            double val(0);
			val = parseDouble();
			return Parser::make_DOUBLE(val, *m_location);
        }

        char currentChar;
        if (m_inStream >> currentChar)
        {
            if (currentChar == '+')
            {
				m_location->columns(1);
				return Parser::make_PLUS(*m_location);
            }
            if (currentChar == '-')
            {
				m_location->columns(1);
				return Parser::make_MINUS(*m_location);
            }
            if (currentChar == '*')
            {
				m_location->columns(1);
				return Parser::make_MULTIPLY(*m_location);
            }
            if (currentChar == '/')
            {
				m_location->columns(1);
				return Parser::make_DIVIDE(*m_location);
            }
            if (currentChar == '(')
            {
				m_location->columns(1);
				return Parser::make_LEFT_P(*m_location);
            }
            if (currentChar == ')')
            {
				m_location->columns(1);
				return Parser::make_RIGHT_P(*m_location);
            }
            
            throw Parser::syntax_error(*m_location, "Unexpected symbol.");
        } 
        else 
        {
			return Parser::make_END(*m_location);
        }
        
    }

    void Scanner::skipSpaces()
    {
        while (m_inStream.get() == ' ')
        {
			m_location->columns(1);
        }
		m_location->step();
        m_inStream.unget();
    }

	double Scanner::parseDouble()
	{
		double value = 0;
		char currentChar;

		while (m_inStream.good())
		{
			currentChar = m_inStream.get();
			if (isdigit(currentChar))
			{
				m_location->columns(1);
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

		m_location->columns(1); // consume .

		double factor = 1;
		while (m_inStream.good())
		{
			currentChar = m_inStream.get();
			if (isdigit(currentChar))
			{
				m_location->columns(1);
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