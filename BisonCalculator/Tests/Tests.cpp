#include "stdafx.h"
#include "Driver.h"

using namespace yy;
using namespace std;

double maxDiff = 0.0001;

BOOST_AUTO_TEST_CASE(CalcValidNumbers)
{
    Driver driver;
    BOOST_CHECK(driver.parseString("5"));
    BOOST_CHECK_CLOSE(driver.getResultValue(), 5, maxDiff);

    BOOST_CHECK(driver.parseString("5.5"));
    BOOST_CHECK_CLOSE(driver.getResultValue(), 5.5, maxDiff);

    BOOST_CHECK(driver.parseString("-0.5"));
    BOOST_CHECK_CLOSE(driver.getResultValue(), -0.5, maxDiff);

    BOOST_CHECK(driver.parseString("(5)"));
    BOOST_CHECK_CLOSE(driver.getResultValue(), 5, maxDiff);

    BOOST_CHECK(driver.parseString("((5))"));
    BOOST_CHECK_CLOSE(driver.getResultValue(), 5, maxDiff);

    BOOST_CHECK(driver.parseString("-(5)"));
    BOOST_CHECK_CLOSE(driver.getResultValue(), -5, maxDiff);

    BOOST_CHECK(driver.parseString("-(-5)"));
    BOOST_CHECK_CLOSE(driver.getResultValue(), 5, maxDiff);

    BOOST_CHECK(driver.parseString("+(-5)"));
    BOOST_CHECK_CLOSE(driver.getResultValue(), -5, maxDiff);

    BOOST_CHECK(driver.parseString("+5"));
    BOOST_CHECK_CLOSE(driver.getResultValue(), 5, maxDiff);
}

BOOST_AUTO_TEST_CASE(CalcValidSumExpression)
{
    Driver driver;
    BOOST_CHECK(driver.parseString("1+2"));
    BOOST_CHECK_CLOSE(driver.getResultValue(), 3, maxDiff);

    BOOST_CHECK(driver.parseString("0+2"));
    BOOST_CHECK_CLOSE(driver.getResultValue(), 2, maxDiff);

    BOOST_CHECK(driver.parseString("1+2.3"));
    BOOST_CHECK_CLOSE(driver.getResultValue(), 3.3, maxDiff);

    BOOST_CHECK(driver.parseString("-1+2"));
    BOOST_CHECK_CLOSE(driver.getResultValue(), 1, maxDiff);

    BOOST_CHECK(driver.parseString("1+-2"));
    BOOST_CHECK_CLOSE(driver.getResultValue(), -1, maxDiff);

    BOOST_CHECK(driver.parseString("(1+2)+3"));
    BOOST_CHECK_CLOSE(driver.getResultValue(), 6, maxDiff);

    BOOST_CHECK(driver.parseString("1+(3+5)"));
    BOOST_CHECK_CLOSE(driver.getResultValue(), 9, maxDiff);

    BOOST_CHECK(driver.parseString("-(1+5)"));
    BOOST_CHECK_CLOSE(driver.getResultValue(), -6, maxDiff);

    BOOST_CHECK(driver.parseString("+(1+5)"));
    BOOST_CHECK_CLOSE(driver.getResultValue(), 6, maxDiff);
}

BOOST_AUTO_TEST_CASE(CalcValidSubstrExpression) 
{
    Driver driver;
    BOOST_CHECK(driver.parseString("1-2"));
    BOOST_CHECK_CLOSE(driver.getResultValue(), -1, maxDiff);

    BOOST_CHECK(driver.parseString("1-2.3"));
    BOOST_CHECK_CLOSE(driver.getResultValue(), -1.3, maxDiff);

    BOOST_CHECK(driver.parseString("-2-5"));
    BOOST_CHECK_CLOSE(driver.getResultValue(), -7, maxDiff);

    BOOST_CHECK(driver.parseString("+0.2-0.2"));
    BOOST_CHECK_CLOSE(driver.getResultValue(), 0, maxDiff);

    BOOST_CHECK(driver.parseString("(0-5)"));
    BOOST_CHECK_CLOSE(driver.getResultValue(), -5, maxDiff);

    BOOST_CHECK(driver.parseString("-(-5-2)"));
    BOOST_CHECK_CLOSE(driver.getResultValue(), 7, maxDiff);

    BOOST_CHECK(driver.parseString("1-(1+5)"));
    BOOST_CHECK_CLOSE(driver.getResultValue(), -5, maxDiff);

    BOOST_CHECK(driver.parseString("(1+5)-6"));
    BOOST_CHECK_CLOSE(driver.getResultValue(), 0, maxDiff);
}

BOOST_AUTO_TEST_CASE(CalcValidMultiplExpression)
{
    Driver driver;
    BOOST_CHECK(driver.parseString("1*2"));
    BOOST_CHECK_CLOSE(driver.getResultValue(), 2, maxDiff);

    BOOST_CHECK(driver.parseString("-1*2.5"));
    BOOST_CHECK_CLOSE(driver.getResultValue(), -2.5, maxDiff);

    BOOST_CHECK(driver.parseString("4*-0.5"));
    BOOST_CHECK_CLOSE(driver.getResultValue(), -2, maxDiff);

    BOOST_CHECK(driver.parseString("0*2"));
    BOOST_CHECK_CLOSE(driver.getResultValue(), 0, maxDiff);

    BOOST_CHECK(driver.parseString("(1*2)*6"));
    BOOST_CHECK_CLOSE(driver.getResultValue(), 12, maxDiff);

    BOOST_CHECK(driver.parseString("5*(1*1)"));
    BOOST_CHECK_CLOSE(driver.getResultValue(), 5, maxDiff);

    BOOST_CHECK(driver.parseString("-(+5*-3)"));
    BOOST_CHECK_CLOSE(driver.getResultValue(), 15, maxDiff);

    BOOST_CHECK(driver.parseString("+(1*2)"));
    BOOST_CHECK_CLOSE(driver.getResultValue(), 2, maxDiff);
}

BOOST_AUTO_TEST_CASE(CalcValidDivExpression)
{
    Driver driver;
    BOOST_CHECK(driver.parseString("1/2"));
    BOOST_CHECK_CLOSE(driver.getResultValue(), 0.5, maxDiff);

    BOOST_CHECK(driver.parseString("10/5.5"));
    BOOST_CHECK_CLOSE(driver.getResultValue(), 1.8181818182, maxDiff);

    BOOST_CHECK(driver.parseString("1/-2"));
    BOOST_CHECK_CLOSE(driver.getResultValue(), -0.5, maxDiff);

    BOOST_CHECK(driver.parseString("-4/2"));
    BOOST_CHECK_CLOSE(driver.getResultValue(), -2, maxDiff);

    BOOST_CHECK(driver.parseString("8/2/+2"));
    BOOST_CHECK_CLOSE(driver.getResultValue(), 2, maxDiff);

    BOOST_CHECK(driver.parseString("(1/2)"));
    BOOST_CHECK_CLOSE(driver.getResultValue(), 0.5, maxDiff);

    BOOST_CHECK(driver.parseString("(1/2)/1"));
    BOOST_CHECK_CLOSE(driver.getResultValue(), 0.5, maxDiff);

    BOOST_CHECK(driver.parseString("5/(1/2)"));
    BOOST_CHECK_CLOSE(driver.getResultValue(), 10, maxDiff);

    BOOST_CHECK(driver.parseString("10.4/2"));
    BOOST_CHECK_CLOSE(driver.getResultValue(), 5.2, maxDiff);
}

BOOST_AUTO_TEST_CASE(CalcValidMixedExpression)
{
    Driver driver;
    BOOST_CHECK(driver.parseString("(1+3)*6/2"));
    BOOST_CHECK_CLOSE(driver.getResultValue(), 12, maxDiff);

    BOOST_CHECK(driver.parseString("5/(1+4)"));
    BOOST_CHECK_CLOSE(driver.getResultValue(), 1, maxDiff);

    BOOST_CHECK(driver.parseString("1+5+2.5-5-2.5"));
    BOOST_CHECK_CLOSE(driver.getResultValue(), 1, maxDiff);

    BOOST_CHECK(driver.parseString("5+2*5+2"));
    BOOST_CHECK_CLOSE(driver.getResultValue(), 17, maxDiff);

    BOOST_CHECK(driver.parseString("5-2-6*2"));
    BOOST_CHECK_CLOSE(driver.getResultValue(), -9, maxDiff);

    BOOST_CHECK(driver.parseString("-1+8/2"));
    BOOST_CHECK_CLOSE(driver.getResultValue(), 3, maxDiff);

    BOOST_CHECK(driver.parseString("(5+2)*(5-2)"));
    BOOST_CHECK_CLOSE(driver.getResultValue(), 21, maxDiff);

    BOOST_CHECK(driver.parseString("5*(-6)/(2-4)"));
    BOOST_CHECK_CLOSE(driver.getResultValue(), 15, maxDiff);

    BOOST_CHECK(driver.parseString("5/6*12/2"));
    BOOST_CHECK_CLOSE(driver.getResultValue(), 5, maxDiff);
}


BOOST_AUTO_TEST_CASE(CalcValidExpressionWithSkippingSpaces)
{
    Driver driver;
    BOOST_CHECK(driver.parseString(" 1"));
    BOOST_CHECK_CLOSE(driver.getResultValue(), 1, maxDiff);

    BOOST_CHECK(driver.parseString("2 "));
    BOOST_CHECK_CLOSE(driver.getResultValue(), 2, maxDiff);

    BOOST_CHECK(driver.parseString(" 3 "));
    BOOST_CHECK_CLOSE(driver.getResultValue(), 3, maxDiff);

    BOOST_CHECK(driver.parseString("  1   "));
    BOOST_CHECK_CLOSE(driver.getResultValue(), 1, maxDiff);

    BOOST_CHECK(driver.parseString("  (1  + -2   ) "));
    BOOST_CHECK_CLOSE(driver.getResultValue(), -1, maxDiff);

    BOOST_CHECK(driver.parseString("  1 / 2"));
    BOOST_CHECK_CLOSE(driver.getResultValue(), 0.5, maxDiff);

    BOOST_CHECK(driver.parseString(" (  4 * 5 ) * 3 + ( 5*5 )"));
    BOOST_CHECK_CLOSE(driver.getResultValue(), 85, maxDiff);
}
    