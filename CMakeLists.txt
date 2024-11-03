# cpp-template-project/CMakeLists.txt

cmake_minimum_required(VERSION 3.10)
project(Homework VERSION 1.0 DESCRIPTION "Zipfs law Homework")

# Define project metadata
set(PROJECT_AUTHOR "Els")
set(PROJECT_NAME "Homework")

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add subdirectories
add_subdirectory(src)
add_subdirectory(tests)
add_subdirectory(docs)

# Include directories
include_directories(include)
enable_testing()