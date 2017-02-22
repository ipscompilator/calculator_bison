#pragma once
#include "IContext.h"

namespace calc
{
	class MockContext : public IContext
	{
	public:
		MockContext() {}

		void ReportIssue(const std::string & msg, const location & loc) override {}
		void PrintResult(double val) override {}
	};
}