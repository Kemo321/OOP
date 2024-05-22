cmake_minimum_required(VERSION 3.14)
project(SVG)

# Set policy to avoid warning about DOWNLOAD_EXTRACT_TIMESTAMP
cmake_policy(SET CMP0135 NEW)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/executables)


# Include GoogleTest
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)


# Add source files
set(SOURCE_FILE
    src/BaseShape.cpp
    src/File.cpp
    src/Image.cpp
    src/Shapes.cpp
    src/main.cpp
)

# Create executable
add_executable(Main ${SOURCE_FILE})

enable_testing()

# Add test source files
set(TEST_SOURCE_FILE
  tests/test_Shapes.cpp
  tests/test_BaseShape.cpp 
  tests/test_Image.cpp
  tests/test_File.cpp
)

# Create test executable
add_executable(Tests ${TEST_SOURCE_FILE} src/BaseShape.cpp src/File.cpp src/Image.cpp src/Shapes.cpp)


target_link_libraries(
  Tests
  gtest_main
)

include(GoogleTest)
gtest_discover_tests(Tests)

target_include_directories(Tests PRIVATE ${CMAKE_SOURCE_DIR}/include)