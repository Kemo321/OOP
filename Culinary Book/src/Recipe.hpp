#pragma once
#include <vector>
#include "Product.hpp"
#include "Recipe.hpp"
#include <fstream>
#include "Product.hpp"
#include <filesystem>




class Recipe
{
protected:
	std::string name;
	std::vector<std::string> steps;
	std::vector<Product> product_list;
	int prepare_time;
	int difficulty;
	int portions;

public:

	Recipe(std::ifstream& pointer);

	std::vector<Product> get_product_list_vector() const;

	std::string get_name() const;

	std::string get_difficulty() const;

	int calculate_calories() const;

	int get_portions() const;

	int get_prepare_time() const;

	friend class Product;

	friend class Book;

	friend std::ostream& operator<<(std::ostream& os, const Recipe& recipe);

	friend std::ifstream& operator>>(std::ifstream& pointer, Recipe& recipe);

	bool operator==(const Recipe& other) const;

	bool operator!=(const Recipe& other) const;
};
