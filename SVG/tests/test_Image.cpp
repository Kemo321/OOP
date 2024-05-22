#include "../src/Shapes.hpp"
#include "../src/Image.hpp"
#include <gtest/gtest.h>

TEST(ImageTest, Constructor) 
{
    Image image("example.html", "100", "200");
    EXPECT_EQ(image.get_length(), 0); // Initial number of shapes should be 0
    EXPECT_EQ(image.get_svg_format(), "<svg version=\"1.1\" \n width=\"100\" height=\"200\"\nxmlns=\"http://www.w3.org/2000/svg\">\n</svg>");
}

TEST(ImageTest, AddAndRemoveShape) 
{
    Image image("example.html", "100", "200");
    std::unique_ptr<Rect> rect = std::make_unique<Rect>();
    std::unique_ptr<Circle> circle = std::make_unique<Circle>();
    std::unique_ptr<Text> text = std::make_unique<Text>();
    std::unique_ptr<Line> line = std::make_unique<Line>();

    image.add_shape(std::move(rect));
    image.add_shape(std::move(circle));
    image.add_shape(std::move(text));
    image.add_shape(std::move(line));

    EXPECT_EQ(image.get_length(), 4); // Number of shapes after adding
    image.remove_shape(2); // Removing the second shape (indexing starts from 1)
    EXPECT_EQ(image.get_length(), 3); // Number of shapes after removing
}

TEST(ImageTest, OutputOperator) 
{
    Image image("example.html", "100", "200");
    std::unique_ptr<Rect> rect = std::make_unique<Rect>();
    image.add_shape(std::move(rect));

    std::ostringstream oss;
    oss << image;

    EXPECT_EQ(oss.str(), "<svg version=\"1.1\" \n width=\"100\" height=\"200\"\nxmlns=\"http://www.w3.org/2000/svg\">\n<rect x=\"0\" y=\"0\" width=\"\" height=\"\" fill=\"\" stroke=\"\"/>\n</svg>");
}
