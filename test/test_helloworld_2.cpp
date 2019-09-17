#include <boost/test/unit_test.hpp>

#include "helloworld.h"

BOOST_AUTO_TEST_CASE( Hello_World_2 )
{
    HelloWorld hello{"Good Night Vienna"};

    BOOST_REQUIRE_EQUAL( hello.getMessage(), "foo");
}