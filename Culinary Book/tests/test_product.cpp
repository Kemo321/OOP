#include <gtest/gtest.h>
#include "../src/Product.cpp"

TEST(ProductTest, CreateProduct1)
{
    Product test_product = Product("abc", 1);
    EXPECT_EQ(test_product.get_calories_per_gram(), 1);
    EXPECT_EQ(test_product.get_name(), "abc");
    EXPECT_EQ(test_product.calculate_calories(5), 5);
}

TEST(ProductTest, CreateProduct2)
{
    Product test_product = Product("Carrot", 2);
    EXPECT_EQ(test_product.get_calories_per_gram(), 2);
    EXPECT_EQ(test_product.get_name(), "Carrot");
    EXPECT_EQ(test_product.calculate_calories(5), 10);
}

TEST(ProductTest, CreateProduct3)
{
    Product test_product = Product("Apple", 1);
    EXPECT_EQ(test_product.get_calories_per_gram(), 1);
    EXPECT_EQ(test_product.get_name(), "Apple");
    EXPECT_EQ(test_product.calculate_calories(5), 5);
}

TEST(ProductTest, CreateProduct4)
{
    Product test_product = Product("Milk", 1);
    EXPECT_EQ(test_product.get_calories_per_gram(), 1);
    EXPECT_EQ(test_product.get_name(), "Milk");
    EXPECT_EQ(test_product.calculate_calories(5), 5);
}

TEST(ProductTest, CreateProduct5)
{
    Product test_product = Product("Beef", 3);
    EXPECT_EQ(test_product.get_calories_per_gram(), 3);
    EXPECT_EQ(test_product.get_name(), "Beef");
    EXPECT_EQ(test_product.calculate_calories(5), 15);
}

TEST(ProductTest, EQ)
{
    Product test_product1 = Product("Beef", 3);
    Product test_product2 = Product("Beef", 3);
    EXPECT_TRUE(test_product1 == test_product2);
}

TEST(ProductTest, NEQ)
{
    Product test_product1 = Product("Beef", 3);
    Product test_product2 = Product("Beef", 4);
    EXPECT_TRUE(test_product1 != test_product2);
}
