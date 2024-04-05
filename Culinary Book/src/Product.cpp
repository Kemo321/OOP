#include "Product.hpp"

Product::Product(const std::string name, const int calories)
{
    this->name = name;
    if (calories >= 0)
        this->calories_per_gram = calories;
    else
        throw std::invalid_argument("Calories cannot be negative");
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

std::ostream& operator<<(std::ostream& os, const Product& product) 
{
    os << "Name: " << product.name << ", Calories per gram: " << product.calories_per_gram;
    return os;
}

std::istream& operator>>(std::istream& is, Product& product) 
{
    std::cout << "Enter name: ";
    is >> product.name;
    std::cout << "Enter calories per gram: ";
    is >> product.calories_per_gram;
    return is;
}

bool Product::operator==(const Product& other) const
{
	return (other.get_name() == this->name && other.get_calories_per_gram() == this->calories_per_gram);
}

bool Product::operator!=(const Product& other) const
{
	return !(*this == other);
}
