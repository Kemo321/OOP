#include <gtest/gtest.h>
#include "../src/Recipe.cpp"


TEST(RecipeTest, CreateRecipe1)
{
    Recipe test_recipe = Recipe("../recipes/Pizza.txt");
    EXPECT_EQ(test_recipe.get_name(), "Pizza");
    EXPECT_EQ(test_recipe.get_difficulty(), "Easy");
    EXPECT_EQ(test_recipe.calculate_calories(), 2130);
    EXPECT_EQ(test_recipe.get_portions(), 4);
    EXPECT_EQ(test_recipe.get_prepare_time(), 780);
}
TEST(RecipeTest, CreateRecipe2)
{
    Recipe test_recipe = Recipe("../recipes/Chicken_Soup.txt");
    EXPECT_EQ(test_recipe.get_name(), "Chicken Soup");
    EXPECT_EQ(test_recipe.get_difficulty(), "Easy");
    EXPECT_EQ(test_recipe.calculate_calories(), 2250);
    EXPECT_EQ(test_recipe.get_portions(), 8);
    EXPECT_EQ(test_recipe.get_prepare_time(), 360);
}

TEST(RecipeTest, CreateRecipe3)
{
    Recipe test_recipe = Recipe("../recipes/Spaghetti.txt");
    EXPECT_EQ(test_recipe.get_name(), "Spaghetti");
    EXPECT_EQ(test_recipe.get_difficulty(), "Intermediate");
    EXPECT_EQ(test_recipe.calculate_calories(), 3000);
    EXPECT_EQ(test_recipe.get_portions(), 4);
    EXPECT_EQ(test_recipe.get_prepare_time(), 120);
}

TEST(RecipeTest, EQ)
{
    Recipe test_recipe1 = Recipe("../recipes/Spaghetti.txt");
    Recipe test_recipe2 = Recipe("../recipes/Spaghetti.txt");
    EXPECT_TRUE(test_recipe1 == test_recipe2);
}

TEST(RecipeTest, NEQ)
{
    Recipe test_recipe1 = Recipe("../recipes/Spaghetti.txt");
    Recipe test_recipe2 = Recipe("../recipes/Chicken_Soup.txt");
    EXPECT_TRUE(test_recipe1 != test_recipe2);
}
