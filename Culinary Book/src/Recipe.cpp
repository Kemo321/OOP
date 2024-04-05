#include "Recipe.hpp"
#include <string>
#include <fstream>
#include "Product.hpp"
#include <filesystem>

Recipe::Recipe(std::string filename)
{
	this->filename = filename;

	if (!std::filesystem::exists(filename))
	{
		return;
		std::cerr << "File containing recipes has not been found" << std::endl;
	}
	try
	{
		std::ifstream read(filename);
		if (!read.is_open()) 
		{
        	std::cerr << "Failed to open recipe file: " << filename << std::endl;
        	return;
		}
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
			this->steps.push_back(temp1);
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
		if (temp1 < "0" || temp1 > "2")
			throw (std::invalid_argument("Wrong difficulty"));
		this->difficulty = std::stoi(temp1);
		// Read portions
		std::getline(read, temp1);
		this->portions = std::stoi(temp1);
		read.close();
	}
	catch(...) 
	{
        std::cerr << "Error while reading recipe file: " << std::endl;
        return;
    }
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
	std::string difficulties[3] = {"Easy", "Intermediate", "Hard"};
	return difficulties[this->difficulty];
}

std::string Recipe::get_filename() const
{
	return this->filename;
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

std::ostream& operator<<(std::ostream& os, const Recipe& recipe)
{
	os << recipe.name;
	return os;
}

std::istream& operator>>(std::istream& is, Recipe& recipe)
{
	is >> recipe.portions;
	return is;
}

bool Recipe::operator==(const Recipe& other) const
{
	return (this->filename == other.get_filename());
}

bool Recipe::operator!=(const Recipe& other) const
{
	return !(*this == other);
}