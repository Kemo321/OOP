#pragma once
#include <vector>
#include "Product.hpp"



class Recipe
{
	std::string filename;
	std::string name;
	std::vector<std::string> steps;
	std::vector<std::pair<Product, int>> product_list;
	int prepare_time;
	int difficulty;
	int portions;

public:

	Recipe(const std::string filename);

	std::vector<std::pair<Product, int>> get_product_list_vector() const;

	std::string get_steps() const;

	std::string get_name() const;

	std::string get_product_list() const;

	std::string get_difficulty() const;
	
	std::string get_filename() const;

	int calculate_calories() const;

	int get_portions() const;

	int get_prepare_time() const;

	friend class Product;

	friend std::ostream& operator<<(std::ostream& os, const Recipe& recipe);

	friend std::istream& operator>>(std::istream& is, Recipe& recipe);

	bool operator==(const Recipe& other) const;

	bool operator!=(const Recipe& other) const;
};
