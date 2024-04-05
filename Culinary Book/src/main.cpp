#include <iostream>
#include <stdlib.h>
#include "Book.hpp"

int main()
{
	Book recipe_book = Book();
	std::string chosen_recipe;
	while(true)
	{
		std::cout << "0. Exit\n";
		recipe_book.show_recipes_list();
		std::cout << "Choose a recipe from the list:" << std::endl;
		std::cin >> chosen_recipe;
		std::cout << std::endl;
		system("CLS");
		if (chosen_recipe == "0")
			break;
		int recipe_index = std::stoi(chosen_recipe);
		system("CLS");
		recipe_book.show_recipe(std::stoi(chosen_recipe));
	}
}