#pragma once
#include <string>
#include "location.hh"

namespace calc
{
	class IContext
	{
	public:
		virtual ~IContext() = default;

		virtual void ReportIssue(const std::string & msg, const location & loc) = 0;
		virtual void PrintResult(double val) = 0;
	};
}