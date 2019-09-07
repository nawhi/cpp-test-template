#define BOOST_TEST_MODULE Hello World Tests
#include <boost/test/unit_test.hpp>

#include "helloworld.h"

BOOST_AUTO_TEST_CASE( Hello_World )
{
    HelloWorld hello{"Good Night Vienna"};

    BOOST_CHECK( hello.getMessage() != "Good Night Vienna");
}