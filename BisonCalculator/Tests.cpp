#include "Driver.h"

#define BOOST_TEST_INCLUDED
#pragma warning (disable: 4702)
#include <boost/test/unit_test.hpp>
#include <boost/algorithm/string/replace.hpp>

#define BOOST_TEST_NO_MAIN 
#include <boost/test/included/unit_test.hpp>

using namespace yy;
using namespace std;

BOOST_AUTO_TEST_CASE(InitializationTest)
{
    Driver driver;
    string expr = "5";
    bool result = driver.parseString(expr);
    BOOST_CHECK(result);
    BOOST_CHECK_EQUAL(driver.resultValue, 5);
}