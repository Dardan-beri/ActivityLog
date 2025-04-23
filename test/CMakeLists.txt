cmake_minimum_required(VERSION 3.5)

add_subdirectory(lib/googletest)

include_directories(
        ${GTEST_INCLUDE_DIRS}
        ${CMAKE_SOURCE_DIR}
)

set(TEST_SOURCE_FILES
        runAllTests.cpp
        ActivityLogTest.cpp
        ActivityTest.cpp)

add_executable(test ${TEST_SOURCE_FILES})

target_link_libraries(test
        core_lib
        gtest_main
        ${wxWidgets_LIBRARIES}
        pthread
        )

enable_testing()
add_test(NAME RunTests COMMAND test)