#include <gtest/gtest.h>
#include "../src/Product.hpp"

TEST(ProductTest, CreateProduct1)
{
    Product test_product = Product("abc 5 1");
    EXPECT_EQ(test_product.get_calories_per_gram(), 1);
    EXPECT_EQ(test_product.get_name(), "abc");
    EXPECT_EQ(test_product.calculate_calories(), 5);
}

TEST(ProductTest, CreateProduct2)
{
    Product test_product = Product("Carrot 5 2");
    EXPECT_EQ(test_product.get_calories_per_gram(), 2);
    EXPECT_EQ(test_product.get_name(), "Carrot");
    EXPECT_EQ(test_product.calculate_calories(), 10);
}

TEST(ProductTest, CreateProduct3)
{
    Product test_product = Product("Apple 5 1");
    EXPECT_EQ(test_product.get_calories_per_gram(), 1);
    EXPECT_EQ(test_product.get_name(), "Apple");
    EXPECT_EQ(test_product.calculate_calories(), 5);
}

TEST(ProductTest, CreateProduct4)
{
    Product test_product = Product("Milk 5 1");
    EXPECT_EQ(test_product.get_calories_per_gram(), 1);
    EXPECT_EQ(test_product.get_name(), "Milk");
    EXPECT_EQ(test_product.calculate_calories(), 5);
}

TEST(ProductTest, CreateProduct5)
{
    Product test_product = Product("Beef 5 3");
    EXPECT_EQ(test_product.get_calories_per_gram(), 3);
    EXPECT_EQ(test_product.get_name(), "Beef");
    EXPECT_EQ(test_product.calculate_calories(), 15);
}

TEST(ProductTest, EQ)
{
    Product test_product1 = Product("Beef 3 3");
    Product test_product2 = Product("Beef 3 3");
    EXPECT_TRUE(test_product1 == test_product2);
}

TEST(ProductTest, NEQ)
{
    Product test_product1 = Product("Beef 3 3");
    Product test_product2 = Product("Beef 4 4");
    EXPECT_TRUE(test_product1 != test_product2);
}

TEST(ProductTest, ID)
{
    Product test_product1 = Product("Beef 3 3");
    std::istringstream is("a a a");
    EXPECT_ANY_THROW(is >> test_product1);
}
