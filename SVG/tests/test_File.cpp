#include <gtest/gtest.h>
#include "../src/File.hpp"
#include <fstream>


// Test fixture for File class
class FileTest : public ::testing::Test 
{
protected:
    std::string filename;

    // SetUp function runs before each test
    void SetUp() override 
    {
        filename = "../../tests/test.txt";
    }

    // TearDown function runs after each test
    void TearDown() override 
    {
        // Delete the test file after each test
        std::remove(filename.c_str());
    }
};

// Test case for constructor
TEST_F(FileTest, Constructor) 
{
    File file(filename);
    file.write("Test");
    ASSERT_TRUE(file.file_exists());
}

// Test case for get_content() method
TEST_F(FileTest, GetContent) 
{
    std::string content = "This is a test file.\nWith multiple lines.\nEnd of file.";

    // Write content to file
    File file(filename);
    file.write(content);

    // Check if content matches
    ASSERT_EQ(file.get_content(), content + "\n");
}

// Test case for write() method
TEST_F(FileTest, Write) {
    std::string content = "This is content to be written.";

    // Write content to file
    File file(filename);
    file.write(content);

    // Check if file exists and content matches
    ASSERT_TRUE(file.file_exists());
    ASSERT_EQ(file.get_content(), content + "\n");
}

// Test case for file_exists() method
TEST_F(FileTest, FileExists) 
{
    // Create an existing file
    std::ofstream ofs("existing_file.txt");
    ofs.close();

    // Check if existing and non-existing files are detected correctly
    File file1("existing_file.txt");
    File file2("non_existing_file.txt");

    ASSERT_TRUE(file1.file_exists());
    ASSERT_FALSE(file2.file_exists());
}

