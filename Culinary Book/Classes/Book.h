#pragma once
#include "Recipe.h"


class Book
{
	std::vector<Recipe> list_of_recipes;

public:

	Book(const std::string recipes_filename="Recipes.txt");

	void show_recipes_list() const;

	void show_recipe(int recipe_number) const;

	std::vector<Recipe> get_list_of_recipes() const;

	friend class Recipe;
};

