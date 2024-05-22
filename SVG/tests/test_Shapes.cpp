#include <gtest/gtest.h>
#include "../src/Shapes.hpp"
#include <sstream>

// Test fixture for Rect class
class RectTest : public ::testing::Test 
{
protected:
    std::string filename;

    // SetUp function runs before each test
    void SetUp() override 
    {
        filename = "test_rect.txt";
    }

    // TearDown function runs after each test
    void TearDown() override 
    {
        // Delete the test file after each test
        std::remove(filename.c_str());
    }
};

// Test case for get_svg_format() method of Rect class
TEST_F(RectTest, GetSvgFormat) 
{
    // Create a Rect object
    Rect rect;
    rect.set_placement({"10", "20"});
    rect.set_width("100");
    rect.set_height("50");
    rect.set_color("red");
    rect.set_stroke("black");

    // Check if the SVG format matches the expected format
    std::string expected_svg = "<rect x=\"10\" y=\"20\" width=\"100\" height=\"50\" fill=\"red\" stroke=\"black\"/>";
    ASSERT_EQ(rect.get_svg_format(), expected_svg);
}

// Test case for load_from_console_shape() method of Rect class
TEST_F(RectTest, LoadFromConsoleShape) 
{
    // Redirect cin to input from stringstream
    std::stringstream input;
    std::streambuf* orig_cin = std::cin.rdbuf(input.rdbuf());

    // Input values for the Rect object
    input << "30\n"; // x coordinate
    input << "40\n"; // y coordinate
    input << "blue\n"; // color
    input << "200\n"; // width
    input << "150\n"; // height
    input << "black"; // stroke


    // Create a Rect object and load values from console
    Rect rect;
    rect.load_from_console_shape();

    // Restore cin
    std::cin.rdbuf(orig_cin);

    // Check if the values are set correctly
    ASSERT_EQ(rect.get_x(), "30");
    ASSERT_EQ(rect.get_y(), "40");
    ASSERT_EQ(rect.get_width(), "200");
    ASSERT_EQ(rect.get_height(), "150");
    ASSERT_EQ(rect.get_color(), "blue");
    ASSERT_EQ(rect.get_stroke(), "black");
}

