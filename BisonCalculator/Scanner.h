#pragma once
#include "Parser.hpp"
#include "location.hh"
#include "StringPool.h"

namespace calc {

	class Scanner
	{
	public:
		Scanner(std::istream &inStream, CStringPool & stringPool);
		~Scanner();
		Parser::token_type Lex(Parser::semantic_type *val, Parser::location_type *loc);

	private:
		void Scanner::SkipSpaces(Parser::location_type *loc);
		double Scanner::ParseDouble(Parser::location_type *loc);
		std::string Scanner::ParseIdentifier(Parser::location_type *loc);
		std::istream &m_inStream;
		CStringPool & m_stringPool;
	};

}