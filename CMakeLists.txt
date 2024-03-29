project(cpp_boost_test_template)
cmake_minimum_required(VERSION 3.5)

enable_testing()

set(CXX_STANDARD 17)
set(CXX_STANDARD_REQUIRED ON)

IF (CMAKE_CXX_COMPILER_ID MATCHES "GNU" OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wshadow -Wformat=2 -std=c++${CXX_STANDARD}")
ELSEIF (MSVC)
  SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
ENDIF()

set(BOOST_INCLUDEDIR 3rd_party/boost/include)
set(BOOST_LIBRARYDIR 3rd_party/boost/lib)

find_package(Boost 
    COMPONENTS unit_test_framework 
    REQUIRED)
include_directories(${Boost_INCLUDE_DIRS} ${CMAKE_SOURCE_DIR}/include)


# build source library
file(GLOB SOURCES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} src/*.cpp)
add_library(cpp_boost_test_template STATIC ${SOURCES})

# build test libraries
file(GLOB TEST_SOURCES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} test/*.cpp)
foreach(testSource ${TEST_SOURCES})
    get_filename_component(testName ${testSource} NAME_WE)
    add_executable(${testName} ${testSource})

    target_link_libraries(${testName} ${Boost_LIBRARIES})

    add_test(NAME ${testName}
            WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/testBin
            COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/testBin/${testName})

endforeach(testSource)