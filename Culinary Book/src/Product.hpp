#pragma once
#include <string>
#include <iostream>


class Product
{
protected:
	std::string name;

	int calories_per_gram;

	int grams;

	std::string grams_str;
	
	std::string calories_per_gram_str;

	bool kilograms;

public:
	Product(std::string content);

	int calculate_calories() const;

	int get_calories_per_gram() const;

	int get_grammature() const;

	std::string get_name() const;

	friend class Recipe;
	
	friend class Book;

	friend std::ostream& operator<<(std::ostream& os, const Product& product);

    friend std::istringstream& operator>>(std::istringstream& is, Product& product);

	bool operator==(const Product& other) const;

	bool operator!=(const Product& other) const;

};