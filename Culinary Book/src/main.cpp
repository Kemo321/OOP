#include <iostream>
#include <stdlib.h>
#include "Book.hpp"

int main()
{
	std::ifstream is("Recipes.txt");
	Book recipe_book = Book(is);
	std::string chosen_recipe;
	while(true)
	{
		std::cout << recipe_book;
		std::cout << "Type 'q' to change unit" << std::endl;
		std::cout << "Choose a recipe from the list:" << std::endl;
		std::cin >> chosen_recipe;
		std::cout << std::endl;
		if (chosen_recipe == "0")
			break;
		if (chosen_recipe == "q")
		{
			recipe_book.change_unit();
			system("CLS");
			continue;
		}
		int recipe_index = std::stoi(chosen_recipe);
		system("CLS");
		recipe_book.show_recipe(std::stoi(chosen_recipe));
	}
}