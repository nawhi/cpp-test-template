#include <doctest.h>

#include "helloworld.h"

TEST_CASE("checking Hello World #2")
{
    HelloWorld hello{"Good Night Vienna"};
    REQUIRE_EQ( hello.getMessage(), "Good Night Vienna");
}