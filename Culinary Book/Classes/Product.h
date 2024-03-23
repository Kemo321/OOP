#pragma once
#include <string>


class Product
{
	std::string name;
	int calories_per_gram;

public:
	Product(const std::string name, const int calories);

	int calculate_calories(const int amount) const;

	int get_calories_per_gram() const;

	std::string get_name() const;

	friend class Recipe;
};

