#pragma once
#include "StringPool.h"
#include "CalcContext.h"
#include "IOutputContext.h"
#include "Scanner.h"
#include "IStatementNode.h"

namespace calc
{
	class Driver
	{
	public:
		using StatementPtr = std::unique_ptr<IStatementNode>;
		using OutputContextPtr = std::shared_ptr<IOutputContext>;

		Driver(OutputContextPtr context);
		~Driver();

		void AddStatement(StatementPtr && statementNode);
		Scanner & GetScanner() const;
		bool ParseStream(std::istream & inStream);
		bool ParseString(const std::string & inString);
		void Error(const std::string & msg, const location & location);

	private:
		std::unique_ptr<Scanner> m_scanner;
		std::vector<StatementPtr> m_statements;
		CStringPool m_stringPool;
		OutputContextPtr m_outputContext;
		std::shared_ptr<CalcContext> m_calcContext;
	};
}