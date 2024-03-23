#include "Recipe.h"
#include <string>
#include <fstream>
#include "Product.h"

Recipe::Recipe(std::string filename)
{
	// Reads the .txt file content and creates an object
	std::ifstream read (filename);
	std::string temp1, temp2, temp3;
	int temp4;
	// Read the name of the recipe
	std::getline(read, temp1);
	this->name = temp1;
	// Read the number of steps
	std::getline(read, temp1);
	temp4 = std::stoi(temp1);
	// Read the steps and put them into steps attr (they are reversed in the file
	for (int i = 0; i < temp4; i++)
	{
		std::getline(read, temp1);
		this->steps.insert(this->steps.begin(), temp1);
	}
	// Read ingredients number
	std::getline(read, temp1);
	temp4 = std::stoi(temp1);
	// Read ingredients and put them in ingredients attr
	for (int i = 0; i < temp4; i++)
	{
		// Read ingredient name
		std::getline(read, temp1);
		// Read ingredient amount (g)
		std::getline(read, temp2);
		// Read calories per (g)
		std::getline(read, temp3);
		// Insert product into ingredients list
		std::pair<Product, int> prod (Product(temp1, std::stoi(temp3)), std::stoi(temp2) );
		this->product_list.insert(this->product_list.begin(), prod);
	}
	// Read and save prepare time (min)
	std::getline(read, temp1);
	this->prepare_time = std::stoi(temp1);
	// Read difficulty (0,1,2)
	std::getline(read, temp1);
	this->difficulty = std::stoi(temp1);
	// Read portions
	std::getline(read, temp1);
	this->portions = std::stoi(temp1);
	read.close();
}

std::vector<std::pair<Product, int>> Recipe::get_product_list_vector() const
{
	return this->product_list;
}

std::string Recipe::get_steps() const
{
	std::string steps_list = "";

	for (int i = 0; i < this->steps.size(); i++)
	{
		steps_list += (this->steps[i] + "\n");
	}
	return steps_list;
}

std::string Recipe::get_name() const
{
	return (this->name);
}

std::string Recipe::get_product_list() const
{
	std::string list;

	for (int i = 0; i < this->product_list.size(); i++)
	{
		list += (std::to_string(i + 1) + ". " + this->product_list[i].first.get_name() + " " + std::to_string(product_list[i].second) + " grams " +
			"Calories per gram: " + std::to_string(this->product_list[i].first.get_calories_per_gram()) + "\n");
	}

	return list;
}

std::string Recipe::get_difficulty() const
{
	std::string difficulty;
	switch (this->difficulty)
	{
	case(0):
		difficulty = "Easy";
		break;
	case(1):
		difficulty = "Intermediate";
		break;
	case(2):
		difficulty = "Hard";
		break;
	}

	return difficulty;
}

int Recipe::calculate_calories() const
{
	int sum = 0;

	for (int i = 0; i < this->product_list.size(); i++)
	{
		sum += this->product_list[i].first.calculate_calories(product_list[i].second);
	}

	return sum;
}

int Recipe::get_portions() const
{
	return (this->portions);
}

int Recipe::get_prepare_time() const
{
	return (this->prepare_time);
}
