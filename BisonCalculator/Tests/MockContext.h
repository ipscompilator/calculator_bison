#pragma once
#include "IOutputContext.h"

namespace calc
{
	class MockContext : public IOutputContext
	{
	public:
		MockContext() {}

		void ReportIssue(const std::string & msg) override {}
		void ReportIssue(const std::string & msg, const location & loc) override {}
		void PrintResult(double val) override {}
	};
}