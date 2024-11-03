FFiles
=====

These are the files included in this submission.

**include/zipfs.h**
-------------------

Header file that provides declarations and implementations for functions related to Zipf's Law analysis.

- Organized into two namespaces:
    - **Session17**: Contains container-based functions (using `std::map`) for counting word frequencies.
    - **Session19**: Contains iterator and algorithm-based functions (using `std::vector` and STL algorithms) for counting word frequencies.

.. doxygenfile:: include/zipfs.h
   :project: Homework

**src/main_zipfs_containers.cpp**
---------------------------------

Main file for processing text files using the container-based approach to analyze word frequencies according to Zipf's Law.

- Uses functions from the `Session17` namespace in `zipfs.h`.

.. doxygenfile:: src/main_zipfs_containers.cpp
   :project: Homework

**src/main_zipfs_algorithms.cpp**
---------------------------------

Main file for processing text files using the iterator and algorithm-based approach to analyze word frequencies according to Zipf's Law.

- Uses functions from the `Session19` namespace in `zipfs.h`.

.. doxygenfile:: src/main_zipfs_algorithms.cpp
   :project: Homework

**tests/zipfs_tests.cpp**
-------------------------

Contains unit tests for functions in `zipfs.h` to validate correct functionality.

- Covers tests for both the `Session17` and `Session19` namespaces.
- Verifies file reading, word frequency computation, and output generation.

.. doxygenfile:: tests/zipfs_tests.cpp
   :project: Homework