CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

SET(CMAKE_CXX_STANDARD 11)

ADD_SUBDIRECTORY(googletest)

ADD_EXECUTABLE(spreadsheet main.cpp spreadsheet.cpp)
ADD_EXECUTABLE(test test.cpp Select_Contains.hpp Select_Not.hpp Select_And.hpp Select_Or.hpp select.hpp spreadsheet.hpp spreadsheet.cpp)

TARGET_LINK_LIBRARIES(test gtest)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)
