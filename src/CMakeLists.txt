cmake_minimum_required(VERSION 3.10)
project(ZipfsLaw)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)

# Include the directory with header files
include_directories(${CMAKE_SOURCE_DIR}/include)

# Add executables for each main file
add_executable(main_zipfs_containers main_zipfs_containers.cpp)
add_executable(main_zipfs_algorithms main_zipfs_algorithms.cpp)