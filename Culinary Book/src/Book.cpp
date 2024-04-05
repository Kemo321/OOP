#include <fstream>
#include <iostream>
#include "Book.hpp"

Book::Book(const std::string recipes_filename)
{
	this->filename = recipes_filename;
	std::ifstream read(recipes_filename);
	std::string number_of_recipes;
	std::getline(read, number_of_recipes);
	int number_of_recipes_int = std::stoi(number_of_recipes);
	for (int i = 0; i < number_of_recipes_int; i++)
	{
		std::string recipe_name;
		std::getline(read, recipe_name);
		this->list_of_recipes.insert(this->list_of_recipes.begin(), Recipe(recipe_name));
	}
	read.close();
};

std::string Book::get_filename() const
{
	return this->filename;
}

void Book::show_recipes_list() const
{
	std::cout << "List of all recipes:" << std::endl;

	for (int i = 0; i < this->list_of_recipes.size(); i++)
	{
		std::cout << i + 1 << ". " << this->list_of_recipes[i].get_name() << std::endl;
	}
}

void Book::show_recipe(int recipe_number) const
{
	recipe_number--;
	std::cout <<"Recipe name: " << this->list_of_recipes[recipe_number].get_name() << std::endl;
	std::cout <<"Difficulty: " << this->list_of_recipes[recipe_number].get_difficulty() << std::endl;
	std::cout << "Portions: " << this->list_of_recipes[recipe_number].get_portions() << std::endl;
	std::cout << "Prepare time(mins): " << this->list_of_recipes[recipe_number].get_prepare_time() << std::endl;
	std::cout << "Calories: " << this->list_of_recipes[recipe_number].calculate_calories() << std::endl;
	std::cout << "Products:" << std::endl << this->list_of_recipes[recipe_number].get_product_list() << std::endl;
	std::cout << this->list_of_recipes[recipe_number].get_steps() << std::endl;
}

std::vector<Recipe> Book::get_list_of_recipes() const
{
	return this->list_of_recipes;
}

bool Book::operator==(const Book& other) const
{
	return (this->filename == other.get_filename());
}

bool Book::operator!=(const Book& other) const
{
	return !(*this == other);
}