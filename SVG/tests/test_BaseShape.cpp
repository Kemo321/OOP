#include <gtest/gtest.h>
#include "../src/BaseShape.hpp"
#include <sstream>

// Test fixture for BaseShape class
class BaseShapeTest : public ::testing::Test 
{
protected:
    std::stringstream input_stream;
    std::stringstream output_stream;

    // SetUp function runs before each test
    void SetUp() override 
    {
        // Redirect standard input/output streams for testing
        std::cin.rdbuf(input_stream.rdbuf());
        std::cout.rdbuf(output_stream.rdbuf());
    }

    // TearDown function runs after each test
    void TearDown() override 
    {
        // Reset standard input/output streams
        std::cin.rdbuf(nullptr);
        std::cout.rdbuf(nullptr);
    }
};

// Test case for constructor
TEST_F(BaseShapeTest, Constructor) 
{
    // Prepare input stream with test values
    input_stream << "5\n10\nblue\n";
    
    // Create a BaseShape object
    BaseShape shape;

    shape.load_from_console_base();

    // Check if shape is initialized correctly
    ASSERT_EQ(shape.get_x(), "5");
    ASSERT_EQ(shape.get_y(), "10");
    ASSERT_EQ(shape.get_color(), "blue");
}

// Test case for load_from_console_base() method
TEST_F(BaseShapeTest, LoadFromConsoleBase) 
{
    // Prepare input stream with test values
    input_stream << "15\n20\nred\n";

    // Create a BaseShape object
    BaseShape shape;

    // Call load_from_console_base() method
    shape.load_from_console_base();

    // Check if shape properties are set correctly
    ASSERT_EQ(shape.get_x(), "15");
    ASSERT_EQ(shape.get_y(), "20");
    ASSERT_EQ(shape.get_color(), "red");
}

// Test case for get_svg_format() method
TEST_F(BaseShapeTest, GetSvgFormat) 
{
    // Create a BaseShape object
    BaseShape shape;

    // Call get_svg_format() method
    std::string svg_format = shape.get_svg_format();

    // Check if svg_format is empty (default behavior)
    ASSERT_TRUE(svg_format.empty());
}

// Test case for operator<< overload
TEST_F(BaseShapeTest, OperatorOutput) 
{
    // Create a BaseShape object
    std::unique_ptr<BaseShape> shape = std::make_unique<BaseShape>();

    // Call operator<< overload
    std::cout << shape;

    // Check if the output stream contains expected SVG format
    ASSERT_EQ(output_stream.str(), "\n");
}
