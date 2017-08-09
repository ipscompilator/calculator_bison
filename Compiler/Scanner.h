#pragma once
#include "Parser.hpp"
#include "location.hh"
#include "StringPool.h"
#include <map>

namespace calc
{
	class Scanner
	{
	public:
		Scanner(std::istream &inStream, CStringPool & stringPool);
		~Scanner();
		Parser::token_type Lex(Parser::semantic_type *val, Parser::location_type *loc);

	private:
		void SkipSpaces(Parser::location_type *loc);
		void SkipTillSeparator(Parser::location_type *loc);
		double ParseDouble(Parser::location_type *loc);
		void CheckIfTokenIsReadToTheEnd(Parser::location_type * loc, std::string failureMessage);
		bool IsSeparatorCharacter(char character);
		bool IsKeyword(std::string identifier);
		std::string Scanner::ParseIdentifier(Parser::location_type *loc);
		std::istream &m_inStream;
		CStringPool & m_stringPool;
		std::map<std::string, Parser::token_type> m_keywordMap = {
			{ "print", Parser::token_type::TOK_PRINT },
			{ "for", Parser::token_type::TOK_FOR },
			{ "if", Parser::token_type::TOK_IF },
			{ "else", Parser::token_type::TOK_ELSE },
		};
		const std::string m_supportedOperators[5] = {"+", "-", "*", "/", "="};
	};
}