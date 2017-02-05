#include "stdafx.h"
#include "Driver.h"

using namespace yy;
using namespace std;

BOOST_AUTO_TEST_CASE(CheckTrue)
{
    Driver driver;
    string expr = "5";
    bool result = driver.parseString(expr);
    BOOST_CHECK(result);
    BOOST_CHECK_EQUAL(driver.resultValue, 4);
}