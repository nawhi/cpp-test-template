
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>

#include "helloworld.h"

TEST_CASE("checking Hello World")
{
    HelloWorld hello{"Good Night Vienna"};
    CHECK( hello.getMessage() == "Good Night Vienna");
}