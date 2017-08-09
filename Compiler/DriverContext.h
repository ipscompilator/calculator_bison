#pragma once
#include "StringPool.h"
#include "IOutputContext.h"

namespace calc
{
	class DriverContext
	{
	public:
		DriverContext(CStringPool & stringPool, std::shared_ptr<IOutputContext> outputContext);
		~DriverContext();

		void AssignVariable(unsigned stringId, double value);
		double GetVariableValue(unsigned stringId)const;
		void PrintResult(double value)const;

	private:
		std::map<unsigned, double> m_variables;
		CStringPool & m_stringPool;
		std::shared_ptr<IOutputContext> m_outputContext;
	};
}
