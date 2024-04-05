#pragma once
#include "Recipe.hpp"


class Book
{
	std::string filename;

	std::vector<Recipe> list_of_recipes;

public:

	Book(const std::string recipes_filename="../recipes/Recipes.txt");

	std::string get_filename() const;

	void show_recipes_list() const;

	void show_recipe(int recipe_number) const;

	std::vector<Recipe> get_list_of_recipes() const;

	friend class Recipe;

	bool operator==(const Book& other) const;

	bool operator!=(const Book& other) const;
};
