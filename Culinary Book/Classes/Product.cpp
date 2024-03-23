#include "Product.h"

Product::Product(const std::string name, const int calories)
{
	this->name = name;
	this->calories_per_gram = calories;
}

int Product::calculate_calories(const int amount) const
{
	return int(amount * this->calories_per_gram);
}

int Product::get_calories_per_gram() const
{
	return this->calories_per_gram;
}

std::string Product::get_name() const
{
	return this->name;
}
