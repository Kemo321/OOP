#include "pch.h"
#include "CppUnitTest.h"
#include "../Classes/Book.cpp"
#include "../Classes/Recipe.cpp"
#include "../Classes/Product.cpp"
#define TEST_CASE_DIRECTORY GetDirectoryName(__FILE__)

// Find absolute path of recipe test files
std::string GetDirectoryName(std::string path) {
	const size_t last_slash_idx = path.rfind('\\');
	if (std::string::npos != last_slash_idx)
	{
		return path.substr(0, last_slash_idx + 1);
	}
	return "";
}

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(UnitTests)
	{
	public:
		
		TEST_METHOD(CreateProduct1)
		{
			Product test_product = Product("abc", 1);
			Assert::IsTrue(test_product.get_calories_per_gram() == 1);
			Assert::IsTrue(test_product.get_name() == "abc");
			Assert::IsTrue(test_product.calculate_calories(5) == 5);
		}

		TEST_METHOD(CreateProduct2)
		{
			Product test_product = Product("Carrot", 2);
			Assert::IsTrue(test_product.get_calories_per_gram() == 2);
			Assert::IsTrue(test_product.get_name() == "Carrot");
			Assert::IsTrue(test_product.calculate_calories(5) == 10);
		}

		TEST_METHOD(CreateProduct3)
		{
			Product test_product = Product("Apple", 1);
			Assert::IsTrue(test_product.get_calories_per_gram() == 1);
			Assert::IsTrue(test_product.get_name() == "Apple");
			Assert::IsTrue(test_product.calculate_calories(5) == 5);
		}

		TEST_METHOD(CreateProduct4)
		{
			Product test_product = Product("Milk", 1);
			Assert::IsTrue(test_product.get_calories_per_gram() == 1);
			Assert::IsTrue(test_product.get_name() == "Milk");
			Assert::IsTrue(test_product.calculate_calories(5) == 5);
		}

		TEST_METHOD(CreateProduct5)
		{
			Product test_product = Product("Beef", 3);
			Assert::IsTrue(test_product.get_calories_per_gram() == 3);
			Assert::IsTrue(test_product.get_name() == "Beef");
			Assert::IsTrue(test_product.calculate_calories(5) == 15);
		}

		TEST_METHOD(CreateRecipe1)
		{
			std::string file = std::string(TEST_CASE_DIRECTORY) + "Pizza.txt";
			Recipe test_recipe = Recipe(file);
			Assert::IsTrue(test_recipe.get_name() == "Pizza");
			Assert::IsTrue(test_recipe.get_difficulty() == "Easy");
			Assert::IsTrue(test_recipe.calculate_calories() == 2130);
			Assert::IsTrue(test_recipe.get_portions() == 4);
			Assert::IsTrue(test_recipe.get_prepare_time() == 780);
		}
		TEST_METHOD(CreateRecipe2)
		{
			std::string file = std::string(TEST_CASE_DIRECTORY) + "Chicken_Soup.txt";
			Recipe test_recipe = Recipe(file);
			Assert::IsTrue(test_recipe.get_name() == "Chicken Soup");
			Assert::IsTrue(test_recipe.get_difficulty() == "Easy");
			Assert::IsTrue(test_recipe.calculate_calories() == 2250);
			Assert::IsTrue(test_recipe.get_portions() == 8);
			Assert::IsTrue(test_recipe.get_prepare_time() == 360);
		}

		TEST_METHOD(CreateRecipe3)
		{
			std::string file = std::string(TEST_CASE_DIRECTORY) + "Spaghetti.txt";
			Recipe test_recipe = Recipe(file);
			Assert::IsTrue(test_recipe.get_name() == "Spaghetti");
			Assert::IsTrue(test_recipe.get_difficulty() == "Intermediate");
			Assert::IsTrue(test_recipe.calculate_calories() == 3000);
			Assert::IsTrue(test_recipe.get_portions() == 4);
			Assert::IsTrue(test_recipe.get_prepare_time() == 120);
		}
	};
}
