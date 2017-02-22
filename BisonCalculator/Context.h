#pragma once
#include "IContext.h"

namespace calc 
{

	class Context : public IContext
	{
	public:
		Context();

		void ReportIssue(const std::string & msg, const location & loc) override;
		void PrintResult(double val) override;
	};

}
