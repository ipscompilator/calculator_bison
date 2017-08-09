#include "stdafx.h"
#include <cctype>
#include <algorithm>
#include <iterator>
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
			loc->lines();
			m_inStream.get();
			
			return Parser::token_type::TOK_EOL;
		}

		if (isdigit(m_inStream.peek()))
		{
			val->doubleVal = ParseDouble(loc);
			return Parser::token_type::TOK_DOUBLE;
		}

		if (isalpha(m_inStream.peek()))
		{
			string identifier = ParseIdentifier(loc);
			if (IsKeyword(identifier))
			{
				return m_keywordMap.at(identifier);
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
				loc->columns();
				return Parser::token_type::TOK_PLUS;
			case '-':
				loc->columns();
				return Parser::token_type::TOK_MINUS;
			case '*':
				loc->columns();
				return Parser::token_type::TOK_MULTIPLY;
			case '/':
				loc->columns();
				return Parser::token_type::TOK_DIVIDE;
			case '(':
				loc->columns();
				return Parser::token_type::TOK_LEFT_BRACKET;
			case ')':
				loc->columns();
				return Parser::token_type::TOK_RIGHT_BRACKET;
			case '=':
				loc->columns();
				return Parser::token_type::TOK_ASSIGN;
			case '{':
				loc->columns();
				return Parser::token_type::TOK_LEFT_BRACE;
			case '}':
				loc->columns();
				return Parser::token_type::TOK_RIGHT_BRACE;
			}
		} 
		else 
		{
			return Parser::token_type::TOK_END;
		}

		SkipTillSeparator(loc);
		throw Parser::syntax_error(*loc, string("Invalid characters, no token is parsed."));
	}

	inline
		Parser::syntax_error::syntax_error(const location_type& l, const std::string& m)
		: std::runtime_error(m)
		, location(l)
	{}

	double Scanner::ParseDouble(Parser::location_type *loc)
	{
		double value = 0;
		char currentChar;
		while (m_inStream.good())
		{
			currentChar = m_inStream.get();
			if (isdigit(currentChar))
			{
				loc->columns();
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
			CheckIfTokenIsReadToTheEnd(loc, "Invalid characters while parsing number.");
			return value;
		}

		loc->columns(); // consume '.'

		double factor = 1;
		while (m_inStream.good())
		{
			currentChar = m_inStream.get();
			if (isdigit(currentChar))
			{
				loc->columns();
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
		CheckIfTokenIsReadToTheEnd(loc, "Invalid characters while parsing number.");

		return value;
	}

	bool Scanner::IsKeyword(string identifier)
	{
		auto it = m_keywordMap.find(identifier);
		return (it != m_keywordMap.end());
	}

	void Scanner::SkipSpaces(Parser::location_type *loc)
	{
		while (m_inStream.get() == ' ')
		{
			loc->columns();
		}
		loc->step();
		m_inStream.unget();
	}

	void Scanner::SkipTillSeparator(Parser::location_type * loc)
	{
		while (!IsSeparatorCharacter(m_inStream.get()))
		{
			loc->columns();
		}
		m_inStream.unget();
	}

	void Scanner::CheckIfTokenIsReadToTheEnd(Parser::location_type *loc, string failureMessage)
	{
		if (!IsSeparatorCharacter(m_inStream.peek()))
		{
			SkipTillSeparator(loc);
			throw Parser::syntax_error(*loc, failureMessage);
		}
	}

	bool Scanner::IsSeparatorCharacter(char character)
	{
		auto it = find(begin(m_supportedOperators), end(m_supportedOperators), string(1, m_inStream.peek()));
		if (it != end(m_supportedOperators)) {
			return true;
		}

		switch (m_inStream.peek())
		{
		case EOF:
		case ' ':
		case '\n':
		case ')':
		case '(':
			return true;
		}

		return false;
	}

	string Scanner::ParseIdentifier(Parser::location_type *loc)
	{
		string identifier;
		char currentChar;

		if (isalpha(m_inStream.peek()))
		{
			identifier += m_inStream.get();
			loc->columns();
		}
		else
		{
			SkipTillSeparator(loc);
			throw Parser::syntax_error(*loc, string("Invalid token, identifier should start with letter."));
		}

		while (m_inStream.good())
		{
			currentChar = m_inStream.get();
			if (isalnum(currentChar) || currentChar == '_')
			{
				loc->columns();
				identifier += currentChar;
			}
			else
			{
				break;
			}
		}

		m_inStream.unget();
		CheckIfTokenIsReadToTheEnd(loc, string("Invalid characters while parsing identifier."));
		return identifier;
	}
}