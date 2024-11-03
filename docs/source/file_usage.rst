File Usage
==========

This section explains the purpose of each file in the project.

* **include/zipfs.h**:
    - Header file containing the function declarations and implementations for processing text files according to Zipf's Law.
    - Organized into two namespaces:
        - **Session17**: Contains functions for the container-based approach (using `std::map`) to count word frequencies.
        - **Session19**: Contains functions for the iterator and algorithm-based approach (using `std::vector` and STL algorithms) to count word frequencies.

* **src/main_zipfs_containers.cpp**:
    - Main file for running the container-based approach to analyze text files according to Zipf's Law.
    - Uses functions from the `Session17` namespace in `zipfs.h` to read a file, compute word frequencies with `std::map`, and output sorted results.

* **src/main_zipfs_algorithms.cpp**:
    - Main file for running the iterator and algorithm-based approach to analyze text files according to Zipf's Law.
    - Uses functions from the `Session19` namespace in `zipfs.h` to read a file, split it into words using iterators, count word frequencies with `std::vector`, and output sorted results.

* **tests/zipfs_tests.cpp**:
    - Contains test cases for the functions in `zipfs.h`, utilizing the Google Test framework to verify correct behavior.
    - Tests cover functionality in both `Session17` and `Session19` namespaces, including:
        - **File reading**: Ensures text files are read and processed correctly.
        - **Word frequency computation**: Verifies that word counts are accurate for both container-based and algorithm-based approaches.
        - **Output**: Confirms that results are output correctly to files.

* **tests/CMakeLists.txt**:
    - CMake configuration file for setting up tests using Google Test.
    - Automatically downloads Google Test if it isn’t present and links it to the test executable.
    - Defines and discovers tests in `zipfs_tests.cpp`.

* **src/CMakeLists.txt**:
    - CMake configuration file for building the main project executables.
    - Compiles `main_zipfs_containers.cpp` and `main_zipfs_algorithms.cpp` separately.
    - Includes the `include` directory and links the necessary source files to each executable.