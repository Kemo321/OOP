#include <fstream>
#include <iostream>
#include "Book.hpp"

Book::Book(std:: ifstream& recipes_file)
{
	recipes_file >> *this;
};


void Book::show_recipe(int recipe_number) const
{
	recipe_number--;
	std::cout << this->list_of_recipes[recipe_number];
}

std::vector<Recipe> Book::get_list_of_recipes() const
{
	return this->list_of_recipes;
}

void Book::change_unit()
{
	for (Recipe& recipe : this->list_of_recipes)
	{
		for (Product& product : recipe.product_list)
		{
			product.kilograms = !product.kilograms;
		}
	}
}

std::ostream& operator<<(std::ostream& os, const Book& Book)
{
	os << "List of all recipes:" << std::endl;
	os << "0. Exit\n";

	for (int i = 0; i < Book.list_of_recipes.size(); i++)
	{
		os << i + 1 << ". " << Book.list_of_recipes[i].get_name() << std::endl;
	}
	return os;
}

std::ifstream& operator>>(std::ifstream& is, Book& Book)
{
	std::string temp2;
	std::getline(is, temp2);

	for (int l=0; l < 3; l++)
	{
		Book.list_of_recipes.push_back(Recipe(is));
	}
	return is;
}

bool Book::operator==(const Book& other) const
{
	return (this->list_of_recipes == other.get_list_of_recipes());
}

bool Book::operator!=(const Book& other) const
{
	return !(*this == other);
}