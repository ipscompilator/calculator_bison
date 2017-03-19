#pragma once
#include "StringPool.h"
#include "CalcContext.h"
#include "CalcNode.h"
#include "IOutputContext.h"
#include "Scanner.h"
#include "StatementNode.h"

namespace calc
{
	class Driver
	{
	public:
		Driver(std::shared_ptr<IOutputContext> context);
		~Driver();

		using StatementPtr = std::unique_ptr<StatementNode>;

		double GetResultValue() const;

		Scanner & GetScanner() const;

		CalcNode & GetCalcNode() const;
		void SetCalcNode(std::unique_ptr<CalcNode> && calcNode);
		void AddStatement(StatementPtr && statementNode);

		bool ParseStream(std::istream & inStream);
		bool ParseString(const std::string & inString);

		void Error(const std::string & msg, const location & location);

		void PrintResult();

	private:
		std::unique_ptr<Scanner> m_scanner;
		std::unique_ptr<CalcNode> m_calcNode;
		std::shared_ptr<IOutputContext> m_outputContext;
		
		std::vector<StatementPtr> m_statements;
		CStringPool m_stringPool;
		std::shared_ptr<CalcContext> m_calcContext;
	};
}