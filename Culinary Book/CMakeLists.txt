cmake_minimum_required(VERSION 3.14)
project(CulinaryBook)

# Set policy to avoid warning about DOWNLOAD_EXTRACT_TIMESTAMP
cmake_policy(SET CMP0135 NEW)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/src)


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
    src/Product.cpp 
    src/Recipe.cpp 
    src/Book.cpp 
    src/main.cpp 
)

# Create executable
add_executable(${PROJECT_NAME} ${SOURCE_FILE})

enable_testing()

# Add test source files
set(TEST_SOURCE_FILE
  tests/test_product.cpp
  tests/test_recipe.cpp
)

# Create test executable
add_executable(tests ${TEST_SOURCE_FILE} src/Product.cpp src/Recipe.cpp src/Book.cpp)


target_link_libraries(
  tests
  gtest_main
)

include(GoogleTest)
gtest_discover_tests(tests)
