project(mykata)
cmake_minimum_required(VERSION 3.5)

enable_testing()

set(CXX_STANDARD 17)
set(CXX_STANDARD_REQUIRED ON)

IF (CMAKE_CXX_COMPILER_ID MATCHES "GNU" OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wshadow -Wformat=2 -std=c++${CXX_STANDARD}")
ELSEIF (MSVC)
  SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
ENDIF()

# build source library
file(GLOB SOURCES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} src/*.cpp)
add_library(mycode STATIC ${SOURCES})
target_include_directories(mycode PUBLIC include)

# build test libraries
file(GLOB TEST_SOURCES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} test/*.cpp)
foreach(testSource ${TEST_SOURCES})
    get_filename_component(testName ${testSource} NAME_WE)
    add_executable(${testName} ${testSource})

    target_include_directories(${testName} PUBLIC 3rd_party)
    target_include_directories(${testName} PUBLIC include)

    target_link_libraries(${testName} mycode)

    add_test(NAME ${testName} COMMAND ${testName})
endforeach(testSource)