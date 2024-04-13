#pragma once
#include "Recipe.hpp"


class Book
{
protected:
	std::vector<Recipe> list_of_recipes;

public:

	Book(std:: ifstream& recipes_file);

	void show_recipe(int recipe_number) const;

	std::vector<Recipe> get_list_of_recipes() const;

	void change_unit();

	friend class Recipe;

	friend std::ostream& operator<<(std::ostream& os, const Book& Book);

	friend std::ifstream& operator>>(std::ifstream& is, Book& Book);

	bool operator==(const Book& other) const;

	bool operator!=(const Book& other) const;
};
