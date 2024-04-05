#pragma once
#include <string>
#include <iostream>


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

	friend std::ostream& operator<<(std::ostream& os, const Product& product);

    friend std::istream& operator>>(std::istream& is, Product& product);

	bool operator==(const Product& other) const;

	bool operator!=(const Product& other) const;

};