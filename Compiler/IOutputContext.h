#pragma once
#include "location.hh"

namespace calc
{
	class IOutputContext
	{
	public:
		virtual ~IOutputContext() = default;

		virtual void ReportIssue(const std::string & msg) = 0;
		virtual void ReportIssue(const std::string & msg, const location & loc) = 0;
		virtual void PrintResult(double val) = 0;
	};
}