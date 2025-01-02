cmake_minimum_required(VERSION 3.5)
add_subdirectory(lib/googletest)
set(gtest_SOURCE_DIR, lib)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
include_directories(${GTEST_INCLUDE_DIRS})

find_package(wxWidgets REQUIRED net gl core base xrc adv )
include(${wxWidgets_USE_FILE})

set(TEST_SOURCE_FILES runAllTests.cpp ActivityLogTest.cpp ActivityLogFixtureTest.cpp)
add_executable(test ${TEST_SOURCE_FILES})
target_link_libraries(test gtest_main core ${wxWidgets_LIBRARIES})
