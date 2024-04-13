#include "Product.hpp"
#include <sstream>

Product::Product(std::string content)
{
    std::istringstream iss(content);
    iss >> this->name >> this->grams_str >> this->calories_per_gram_str;
    if (std::stoi(this->grams_str) <= 0 || std::stoi(this->calories_per_gram_str) < 0)
    {
        throw std::invalid_argument("Incorrect product data");
    }
    this->calories_per_gram = std::stoi(calories_per_gram_str);
    this->grams = std::stoi(grams_str);
}

int Product::calculate_calories() const
{
	return int(this->grams * this->calories_per_gram);
}

int Product::get_calories_per_gram() const
{
	return this->calories_per_gram;
}

int Product::get_grammature() const
{
    return this->grams;
}

std::string Product::get_name() const
{
	return this->name;
}

std::ostream& operator<<(std::ostream& os, const Product& product) 
{
    if (product.kilograms)
        os << "Ingredient: " << product.name <<" Kilograms: " << float(product.grams) / 1000 << " Calories per kilogram: " << float(product.calories_per_gram) / 1000 << std::endl;
    else
        os << "Ingredient: " << product.name <<" Grams: " << product.grams << " Calories per gram: " << product.calories_per_gram << std::endl;
    return os;
}

std::istringstream& operator>>(std::istringstream& is, Product& product) 
{
    is >> product.name >> product.grams_str >> product.calories_per_gram_str;
    product.grams = std::stoi(product.grams_str);
    product.calories_per_gram = std::stoi(product.calories_per_gram_str);
    return is;
}

bool Product::operator==(const Product& other) const
{
	return (other.get_name() == this->name && other.get_calories_per_gram() == this->calories_per_gram && this->grams == other.get_grammature());
}

bool Product::operator!=(const Product& other) const
{
	return !(*this == other);
}
