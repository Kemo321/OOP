#include <gtest/gtest.h>
#include "../src/Book.hpp"

TEST(RecipeTest, CreateBook)
{
    std::ifstream test("../src/Recipes.txt");
    Book test_book(test);

    std::vector<Recipe> test_vector = test_book.get_list_of_recipes();

    Recipe& test_recipe1 = test_vector[0];
    Recipe& test_recipe2 = test_vector[1];
    Recipe& test_recipe3 = test_vector[2];

    EXPECT_EQ(test_recipe1.get_name(), "Chicken Soup");
    EXPECT_EQ(test_recipe1.get_difficulty(), "Easy");
    EXPECT_EQ(test_recipe1.calculate_calories(), 2250);
    EXPECT_EQ(test_recipe1.get_portions(), 8);
    EXPECT_EQ(test_recipe1.get_prepare_time(), 360);

    EXPECT_EQ(test_recipe2.get_name(), "Pizza");
    EXPECT_EQ(test_recipe2.get_difficulty(), "Easy");
    EXPECT_EQ(test_recipe2.calculate_calories(), 2130);
    EXPECT_EQ(test_recipe2.get_portions(), 3);
    EXPECT_EQ(test_recipe2.get_prepare_time(), 780);

    EXPECT_EQ(test_recipe3.get_name(), "Spaghetti");
    EXPECT_EQ(test_recipe3.get_difficulty(), "Intermediate");
    EXPECT_EQ(test_recipe3.calculate_calories(), 3000);
    EXPECT_EQ(test_recipe3.get_portions(), 4);
    EXPECT_EQ(test_recipe3.get_prepare_time(), 120);
}
