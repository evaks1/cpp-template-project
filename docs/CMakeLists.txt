# docs/CMakeLists.txt

cmake_minimum_required(VERSION 3.10)
project(Homework)

# Set project metadata (if not already set in the root CMakeLists.txt)
set(PROJECT_AUTHOR "Els")
set(PROJECT_NAME "Homework")

find_package(Doxygen REQUIRED)
if(DOXYGEN_FOUND)
    set(DOXYFILE_IN ${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in)
    set(DOXYFILE_OUT ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)

    # Update the input directory to point to 'src' and 'include'
    set(DOXYGEN_INPUT_DIR "${CMAKE_SOURCE_DIR}/src ${CMAKE_SOURCE_DIR}/include")

    # Set the output directory for Doxygen
    set(DOXYGEN_OUTPUT_DIR "${CMAKE_CURRENT_BINARY_DIR}/doxygen/xml")

    # Configure the Doxyfile
    configure_file(${DOXYFILE_IN} ${DOXYFILE_OUT} @ONLY)

    # Create the output directory
    file(MAKE_DIRECTORY ${DOXYGEN_OUTPUT_DIR})

    # Collect header files for dependencies
    file(GLOB_RECURSE PUBLIC_HEADERS "${DOXYGEN_INPUT_DIR}/*.h" "${DOXYGEN_INPUT_DIR}/*.hpp")

    # Add custom command to generate Doxygen documentation
    add_custom_command(
        OUTPUT ${DOXYGEN_OUTPUT_DIR}/index.xml
        COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYFILE_OUT}
        DEPENDS ${PUBLIC_HEADERS} ${DOXYFILE_OUT}
        COMMENT "Generating API documentation with Doxygen"
        VERBATIM
    )

    # Add custom target
    add_custom_target(doc_doxygen ALL
        DEPENDS ${DOXYGEN_OUTPUT_DIR}/index.xml
    )
else()
    message(FATAL_ERROR "Doxygen is required to build the documentation.")
endif()

# Find Sphinx
find_program(SPHINX_BUILD_EXECUTABLE sphinx-build)
if(NOT SPHINX_BUILD_EXECUTABLE)
    message(FATAL_ERROR "sphinx-build not found. Please install Sphinx.")
endif()

# Add custom target for Sphinx
add_custom_target(doc_sphinx ALL
    COMMAND ${SPHINX_BUILD_EXECUTABLE} -b html
        -d "${CMAKE_CURRENT_BINARY_DIR}/sphinx/doctrees"
        "${CMAKE_CURRENT_SOURCE_DIR}/source"
        "${CMAKE_CURRENT_BINARY_DIR}/sphinx"
    DEPENDS doc_doxygen
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    COMMENT "Generating documentation with Sphinx"
    VERBATIM
)