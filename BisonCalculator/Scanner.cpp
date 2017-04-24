#include "stdafx.h"
#include <cctype>
#include "Scanner.h"
#include "PointerHelpers.h"

using namespace std;

namespace calc {

	Scanner::Scanner(std::istream &inStream, CStringPool & stringPool)
		: m_inStream(inStream)
		, m_stringPool(stringPool)
	{
	}

	Scanner::~Scanner()
	{
	}

	Parser::token_type Scanner::Lex(Parser::semantic_type *val, Parser::location_type *loc)
	{
		loc->step();
		if (m_inStream.peek() == ' ')
		{
			SkipSpaces(loc);
		}

		if (m_inStream.peek() == '\n')
		{
			loc->lines(1);
			m_inStream.get();
			
			return Parser::token_type::TOK_EOL;
		}

		if (isdigit(m_inStream.peek()))
		{
			val->doubleVal = ParseDouble(loc);
			return Parser::token_type::TOK_DOUBLE;
		}

		if (isalnum(m_inStream.peek()))
		{
			string identifier = ParseIdentifier(loc);
			if (identifier == "print")
			{
				return Parser::token_type::TOK_PRINT;
			}
			else
			{
				val->stringId = m_stringPool.Insert(identifier);
				return Parser::token_type::TOK_IDENTIFIER;
			}
		}

		char currentChar;
		if (m_inStream >> currentChar)
		{
			switch (currentChar)
			{
			case '+':
				loc->columns(1);
				return Parser::token_type::TOK_PLUS;
			case '-':
				loc->columns(1);
				return Parser::token_type::TOK_MINUS;
			case '*':
				loc->columns(1);
				return Parser::token_type::TOK_MULTIPLY;
			case '/':
				loc->columns(1);
				return Parser::token_type::TOK_DIVIDE;
			case '(':
				loc->columns(1);
				return Parser::token_type::TOK_LEFT_P;
			case ')':
				loc->columns(1);
				return Parser::token_type::TOK_RIGHT_P;
			case '=':
				loc->columns(1);
				return Parser::token_type::TOK_ASSIGN;
			}
		} 
		else 
		{
			return Parser::token_type::TOK_END;
		}
	}

	void Scanner::SkipSpaces(Parser::location_type *loc)
	{
		while (m_inStream.get() == ' ')
		{
			loc->columns(1);
		}
		loc->step();
		m_inStream.unget();
	}

	double Scanner::ParseDouble(Parser::location_type *loc)
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

	string Scanner::ParseIdentifier(Parser::location_type *loc)
	{
		string identifier;
		char currentChar;

		if (isalnum(m_inStream.peek()))
		{
			identifier += m_inStream.get();
			loc->columns(1);
		}
		else
		{
			return identifier;
		}

		while (m_inStream.good())
		{
			currentChar = m_inStream.get();
			if (isalnum(currentChar))
			{
				loc->columns(1);
				identifier += currentChar;
			}
			else
			{
				break;
			}
		}

		m_inStream.unget();
		return identifier;
	}
}