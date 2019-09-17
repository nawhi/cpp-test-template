# These 2 lines required by all CMakeLists.txt files
cmake_minimum_required(VERSION 3.5)
project(mykata)

# Enforce C++17
set(CXX_STANDARD 17)
set(CXX_STANDARD_REQUIRED ON)

# Add compilation flags
IF (CMAKE_CXX_COMPILER_ID MATCHES "GNU" OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wshadow -Wformat=2 -std=c++${CXX_STANDARD}")
ELSEIF (MSVC)
  SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
ENDIF()

# Source library
# NB: as this gets bigger will probably want to move it to
# its own CMakeLists.txt in the src subdirectory
file(GLOB SOURCES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} src/*.cpp)
add_library(mycode STATIC ${SOURCES})
target_include_directories(mycode PUBLIC include)

# Build test executable
enable_testing()
file(GLOB TEST_SOURCES test/*.cpp)
add_executable(unit_tests ${TEST_SOURCES})

# Unit test framework (UTF) header lives in 3rd_party
target_include_directories(unit_tests PUBLIC 3rd_party/boost/include)

# Link headers and library from business code
target_include_directories(unit_tests PUBLIC include)
target_link_libraries(unit_tests mycode)

# Compile and link all files in test directory to test executable
target_link_directories(unit_tests PUBLIC test)

# Add the executable as a test, so CTest can find it
add_test(NAME all_tests COMMAND unit_tests)

# Make CTest show full output (by default, it only shows pass/fail)
add_custom_target(check COMMAND ${CMAKE_MAKE_PROGRAM} && ${CMAKE_CTEST_COMMAND} --verbose)