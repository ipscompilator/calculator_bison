#pragma once
#include "StringPool.h"
#include "CalcContext.h"
#include "IOutputContext.h"
#include "Scanner.h"
#include "IStatementNode.h"
#include "BlockNode.h"

namespace calc
{
	class Driver
	{
	public:
		using StatementPtr = std::unique_ptr<IStatementNode>;
		using OutputContextPtr = std::shared_ptr<IOutputContext>;

		Driver(OutputContextPtr context);
		~Driver();

		Parser::token_type Advance(Parser::semantic_type *val, Parser::location_type *loc);
		void AddStatement(StatementPtr && statementNode);
		bool ParseStream(std::istream & inStream);
		bool ParseString(const std::string & inString);
		void Error(const std::string & msg, const location & location);
		void PrintProgram();

	private:
		std::unique_ptr<Scanner> m_scanner;
		CStringPool m_stringPool;
		OutputContextPtr m_outputContext;
		std::shared_ptr<CalcContext> m_calcContext;
		BlockNode m_program;
	};
}