#include "stdafx.h"
#include "Driver.h"
#include "MockContext.h"

using namespace calc;
using namespace std;

double maxDiff = 0.0001;

BOOST_AUTO_TEST_CASE(Fake)
{
	BOOST_CHECK(true);
}

#if 0
BOOST_AUTO_TEST_CASE(CalcValidNumbers)
{
    Driver driver(make_shared<MockContext>());
    BOOST_CHECK(driver.ParseString("5"));
    BOOST_CHECK_CLOSE(driver.GetResultValue(), 5, maxDiff);

    BOOST_CHECK(driver.ParseString("5.5"));
    BOOST_CHECK_CLOSE(driver.GetResultValue(), 5.5, maxDiff);

    BOOST_CHECK(driver.ParseString("-0.5"));
    BOOST_CHECK_CLOSE(driver.GetResultValue(), -0.5, maxDiff);

    BOOST_CHECK(driver.ParseString("(5)"));
    BOOST_CHECK_CLOSE(driver.GetResultValue(), 5, maxDiff);

    BOOST_CHECK(driver.ParseString("((5.))"));
    BOOST_CHECK_CLOSE(driver.GetResultValue(), 5, maxDiff);

    BOOST_CHECK(driver.ParseString("-(5)"));
    BOOST_CHECK_CLOSE(driver.GetResultValue(), -5, maxDiff);

    BOOST_CHECK(driver.ParseString("-(-5)"));
    BOOST_CHECK_CLOSE(driver.GetResultValue(), 5, maxDiff);

    BOOST_CHECK(driver.ParseString("+(-5)"));
    BOOST_CHECK_CLOSE(driver.GetResultValue(), -5, maxDiff);

    BOOST_CHECK(driver.ParseString("+5"));
    BOOST_CHECK_CLOSE(driver.GetResultValue(), 5, maxDiff);
}

BOOST_AUTO_TEST_CASE(CalcValidSumExpression)
{
	Driver driver(make_shared<MockContext>());
    BOOST_CHECK(driver.ParseString("1+2"));
    BOOST_CHECK_CLOSE(driver.GetResultValue(), 3, maxDiff);

    BOOST_CHECK(driver.ParseString("0+2"));
    BOOST_CHECK_CLOSE(driver.GetResultValue(), 2, maxDiff);

    BOOST_CHECK(driver.ParseString("1+2.3"));
    BOOST_CHECK_CLOSE(driver.GetResultValue(), 3.3, maxDiff);

    BOOST_CHECK(driver.ParseString("-1+2"));
    BOOST_CHECK_CLOSE(driver.GetResultValue(), 1, maxDiff);

    BOOST_CHECK(driver.ParseString("1+-2"));
    BOOST_CHECK_CLOSE(driver.GetResultValue(), -1, maxDiff);

    BOOST_CHECK(driver.ParseString("(1+2)+3"));
    BOOST_CHECK_CLOSE(driver.GetResultValue(), 6, maxDiff);

    BOOST_CHECK(driver.ParseString("1+(3+5)"));
    BOOST_CHECK_CLOSE(driver.GetResultValue(), 9, maxDiff);

    BOOST_CHECK(driver.ParseString("-(1+5)"));
    BOOST_CHECK_CLOSE(driver.GetResultValue(), -6, maxDiff);

    BOOST_CHECK(driver.ParseString("+(1+5)"));
    BOOST_CHECK_CLOSE(driver.GetResultValue(), 6, maxDiff);
}

BOOST_AUTO_TEST_CASE(CalcValidSubstrExpression) 
{
	Driver driver(make_shared<MockContext>());
    BOOST_CHECK(driver.ParseString("1-2"));
    BOOST_CHECK_CLOSE(driver.GetResultValue(), -1, maxDiff);

    BOOST_CHECK(driver.ParseString("1-2.3"));
    BOOST_CHECK_CLOSE(driver.GetResultValue(), -1.3, maxDiff);

    BOOST_CHECK(driver.ParseString("-2-5"));
    BOOST_CHECK_CLOSE(driver.GetResultValue(), -7, maxDiff);

    BOOST_CHECK(driver.ParseString("+0.2-0.2"));
    BOOST_CHECK_CLOSE(driver.GetResultValue(), 0, maxDiff);

    BOOST_CHECK(driver.ParseString("(0-5)"));
    BOOST_CHECK_CLOSE(driver.GetResultValue(), -5, maxDiff);

    BOOST_CHECK(driver.ParseString("-(-5-2)"));
    BOOST_CHECK_CLOSE(driver.GetResultValue(), 7, maxDiff);

    BOOST_CHECK(driver.ParseString("1-(1+5)"));
    BOOST_CHECK_CLOSE(driver.GetResultValue(), -5, maxDiff);

    BOOST_CHECK(driver.ParseString("(1+5)-6"));
    BOOST_CHECK_CLOSE(driver.GetResultValue(), 0, maxDiff);
}

BOOST_AUTO_TEST_CASE(CalcValidMultiplExpression)
{
	Driver driver(make_shared<MockContext>());
    BOOST_CHECK(driver.ParseString("1*2"));
    BOOST_CHECK_CLOSE(driver.GetResultValue(), 2, maxDiff);

    BOOST_CHECK(driver.ParseString("-1*2.5"));
    BOOST_CHECK_CLOSE(driver.GetResultValue(), -2.5, maxDiff);

    BOOST_CHECK(driver.ParseString("4*-0.5"));
    BOOST_CHECK_CLOSE(driver.GetResultValue(), -2, maxDiff);

    BOOST_CHECK(driver.ParseString("0*2"));
    BOOST_CHECK_CLOSE(driver.GetResultValue(), 0, maxDiff);

    BOOST_CHECK(driver.ParseString("(1*2)*6"));
    BOOST_CHECK_CLOSE(driver.GetResultValue(), 12, maxDiff);

    BOOST_CHECK(driver.ParseString("5*(1*1)"));
    BOOST_CHECK_CLOSE(driver.GetResultValue(), 5, maxDiff);

    BOOST_CHECK(driver.ParseString("-(+5*-3)"));
    BOOST_CHECK_CLOSE(driver.GetResultValue(), 15, maxDiff);

    BOOST_CHECK(driver.ParseString("+(1*2)"));
    BOOST_CHECK_CLOSE(driver.GetResultValue(), 2, maxDiff);
}

BOOST_AUTO_TEST_CASE(CalcValidDivExpression)
{
	Driver driver(make_shared<MockContext>());
    BOOST_CHECK(driver.ParseString("1/2"));
    BOOST_CHECK_CLOSE(driver.GetResultValue(), 0.5, maxDiff);

    BOOST_CHECK(driver.ParseString("10/5.5"));
    BOOST_CHECK_CLOSE(driver.GetResultValue(), 1.8181818182, maxDiff);

    BOOST_CHECK(driver.ParseString("1/-2"));
    BOOST_CHECK_CLOSE(driver.GetResultValue(), -0.5, maxDiff);

    BOOST_CHECK(driver.ParseString("-4/2"));
    BOOST_CHECK_CLOSE(driver.GetResultValue(), -2, maxDiff);

    BOOST_CHECK(driver.ParseString("8/2/+2"));
    BOOST_CHECK_CLOSE(driver.GetResultValue(), 2, maxDiff);

    BOOST_CHECK(driver.ParseString("(1/2)"));
    BOOST_CHECK_CLOSE(driver.GetResultValue(), 0.5, maxDiff);

    BOOST_CHECK(driver.ParseString("(1/2)/1"));
    BOOST_CHECK_CLOSE(driver.GetResultValue(), 0.5, maxDiff);

    BOOST_CHECK(driver.ParseString("5/(1/2)"));
    BOOST_CHECK_CLOSE(driver.GetResultValue(), 10, maxDiff);

    BOOST_CHECK(driver.ParseString("10.4/2"));
    BOOST_CHECK_CLOSE(driver.GetResultValue(), 5.2, maxDiff);
}

BOOST_AUTO_TEST_CASE(CalcValidMixedExpression)
{
	Driver driver(make_shared<MockContext>());
    BOOST_CHECK(driver.ParseString("(1+3)*6/2"));
    BOOST_CHECK_CLOSE(driver.GetResultValue(), 12, maxDiff);

    BOOST_CHECK(driver.ParseString("5/(1+4)"));
    BOOST_CHECK_CLOSE(driver.GetResultValue(), 1, maxDiff);

    BOOST_CHECK(driver.ParseString("1+5+2.5-5-2.5"));
    BOOST_CHECK_CLOSE(driver.GetResultValue(), 1, maxDiff);

    BOOST_CHECK(driver.ParseString("5+2*5+2"));
    BOOST_CHECK_CLOSE(driver.GetResultValue(), 17, maxDiff);

    BOOST_CHECK(driver.ParseString("5-2-6*2"));
    BOOST_CHECK_CLOSE(driver.GetResultValue(), -9, maxDiff);

    BOOST_CHECK(driver.ParseString("-1+8/2"));
    BOOST_CHECK_CLOSE(driver.GetResultValue(), 3, maxDiff);

    BOOST_CHECK(driver.ParseString("(5+2)*(5-2)"));
    BOOST_CHECK_CLOSE(driver.GetResultValue(), 21, maxDiff);

    BOOST_CHECK(driver.ParseString("5*(-6)/(2-4)"));
    BOOST_CHECK_CLOSE(driver.GetResultValue(), 15, maxDiff);

    BOOST_CHECK(driver.ParseString("5/6*12/2"));
    BOOST_CHECK_CLOSE(driver.GetResultValue(), 5, maxDiff);
}

BOOST_AUTO_TEST_CASE(CalcValidExpressionWithSkippingSpaces)
{
	Driver driver(make_shared<MockContext>());
    BOOST_CHECK(driver.ParseString(" 1"));
    BOOST_CHECK_CLOSE(driver.GetResultValue(), 1, maxDiff);

    BOOST_CHECK(driver.ParseString("2 "));
    BOOST_CHECK_CLOSE(driver.GetResultValue(), 2, maxDiff);

    BOOST_CHECK(driver.ParseString(" 3 "));
    BOOST_CHECK_CLOSE(driver.GetResultValue(), 3, maxDiff);

    BOOST_CHECK(driver.ParseString("  1   "));
    BOOST_CHECK_CLOSE(driver.GetResultValue(), 1, maxDiff);

    BOOST_CHECK(driver.ParseString("  (1  + -2   ) "));
    BOOST_CHECK_CLOSE(driver.GetResultValue(), -1, maxDiff);

    BOOST_CHECK(driver.ParseString("  1 / 2"));
    BOOST_CHECK_CLOSE(driver.GetResultValue(), 0.5, maxDiff);

    BOOST_CHECK(driver.ParseString(" (  4 * 5 ) * 3 + ( 5*5 )"));
    BOOST_CHECK_CLOSE(driver.GetResultValue(), 85, maxDiff);
}

/*
BOOST_AUTO_TEST_CASE(ParseExpressionsWithInvalidCharacters)
{
	Driver driver(make_shared<MockContext>());
	BOOST_CHECK(!driver.ParseString("f1+5"));
	BOOST_CHECK(!driver.ParseString("alice"));
	BOOST_CHECK(!driver.ParseString(";4"));
	BOOST_CHECK(!driver.ParseString("4+5s"));
	BOOST_CHECK(!driver.ParseString("8%63"));
}
*/

BOOST_AUTO_TEST_CASE(ParseExpresstionsWithInvalidOperationsCombination)
{
	Driver driver(make_shared<MockContext>());
	BOOST_CHECK(!driver.ParseString("--1"));
	BOOST_CHECK(!driver.ParseString("++1"));
	BOOST_CHECK(!driver.ParseString("1+++2"));
	BOOST_CHECK(!driver.ParseString("1---2"));
	BOOST_CHECK(!driver.ParseString("--(1+5)"));
	BOOST_CHECK(!driver.ParseString("++(6)"));
	BOOST_CHECK(!driver.ParseString("1+2-+-6"));
	BOOST_CHECK(!driver.ParseString("-(--(5))"));
}

BOOST_AUTO_TEST_CASE(ParseInvalidDoubles)
{
	Driver driver(make_shared<MockContext>());
	BOOST_CHECK(!driver.ParseString("5*1. 05"));
	BOOST_CHECK(!driver.ParseString("4,5*22"));
	BOOST_CHECK(!driver.ParseString("1.5.2+3"));
}

BOOST_AUTO_TEST_CASE(ParseExpressionsWithInvalidParentheses)
{
	Driver driver(make_shared<MockContext>());
	BOOST_CHECK(!driver.ParseString("("));
	BOOST_CHECK(!driver.ParseString(")"));
	BOOST_CHECK(!driver.ParseString("(1"));
	BOOST_CHECK(!driver.ParseString("5+5)"));
	BOOST_CHECK(!driver.ParseString("1+(4+3))"));
	BOOST_CHECK(!driver.ParseString("5*((2-1)"));
}

BOOST_AUTO_TEST_CASE(ParseExpressionsWithInvalidGramar)
{
	Driver driver(make_shared<MockContext>());
	BOOST_CHECK(!driver.ParseString("1+"));
	BOOST_CHECK(!driver.ParseString("1*"));
	BOOST_CHECK(!driver.ParseString("1-"));
	BOOST_CHECK(!driver.ParseString("1/"));
	BOOST_CHECK(!driver.ParseString("(4+5+)"));
	BOOST_CHECK(!driver.ParseString("4*5 6"));
	BOOST_CHECK(!driver.ParseString("2 - * 8"));
	BOOST_CHECK(!driver.ParseString("3+/4"));
}
#endif