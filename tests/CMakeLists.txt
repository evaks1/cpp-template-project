cmake_minimum_required(VERSION 3.14)

# Enable testing
enable_testing()

# Fetch GoogleTest
include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG v1.15.1  # Adjust the version as needed
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Include directories
include_directories(${CMAKE_SOURCE_DIR}/include)

# List of test source files (only zipfs_tests.cpp now)
set(TEST_SOURCES
    zipfs_tests.cpp
)

# Include GoogleTest CMake module
include(GoogleTest)

# Iterate over each test source file to create targets
foreach(test_source ${TEST_SOURCES})
    # Get the test name by stripping the directory and extension
    get_filename_component(test_name ${test_source} NAME_WE)

    # Create an executable for the test
    add_executable(${test_name} ${test_source})

    # Link libraries
    target_link_libraries(${test_name} PRIVATE GTest::gtest_main)

    # Optionally, set C++ standard if needed (e.g., C++14)
    # target_compile_features(${test_name} PRIVATE cxx_std_14)

    # Add test to CTest
    add_test(NAME ${test_name} COMMAND ${test_name})

    # Discover tests
    gtest_discover_tests(${test_name})
endforeach()