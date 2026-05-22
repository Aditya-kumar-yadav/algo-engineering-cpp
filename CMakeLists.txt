cmake_minimum_required(VERSION 3.14)
project(LeetCodeEnterprise CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 🛡️ ENTERPRISE STANDARD: Strict Compiler Warnings
# This fails the build if there is even a single warning.
if(MSVC)
    # Windows / Visual Studio compiler flags
    add_compile_options(/W4 /WX)
else()
    # Linux / Mac / MinGW compiler flags
    add_compile_options(-Wall -Wextra -Werror)
endif()

# Download and incorporate Google Test
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Enable testing
enable_testing()

# Include your source files so the tests can find them
include_directories(src)

# --- AUTO-DISCOVER AND REGISTER ALL TESTS ---

# 1. Search the tests/ folder for any file ending in "_test.cpp"
file(GLOB_RECURSE TEST_SOURCES "tests/*_test.cpp")

# 2. Loop through every test file it found
foreach(TEST_FILE ${TEST_SOURCES})
    
    # Extract just the name of the file (e.g., "two_sum_test" from "tests/arrays/two_sum_test.cpp")
    get_filename_component(TEST_NAME ${TEST_FILE} NAME_WE)
    
    # Create the executable for this specific test
    add_executable(${TEST_NAME} ${TEST_FILE})
    
    # Link Google Test to it
    target_link_libraries(${TEST_NAME} gtest_main)
    
    # Register it so `ctest` knows it exists
    add_test(NAME ${TEST_NAME} COMMAND ${TEST_NAME})
    
endforeach()