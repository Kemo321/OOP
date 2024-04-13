#include "Recipe.hpp"

Recipe::Recipe(std::ifstream& pointer)
{
	pointer >> *this;
}

std::vector<Product> Recipe::get_product_list_vector() const
{
	return this->product_list;
}

std::string Recipe::get_name() const
{
	return (this->name);
}

std::string Recipe::get_difficulty() const
{
	std::string difficulties[3] = {"Easy", "Intermediate", "Hard"};
	return difficulties[this->difficulty];
}

int Recipe::calculate_calories() const
{
	int sum = 0;

	for (int i = 0; i < this->product_list.size(); i++)
	{
		sum += this->product_list[i].calculate_calories();
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
    os << "Recipe Name: " << recipe.name << "\n"
       << "Prepare Time: " << recipe.prepare_time << " minutes\n"
       << "Difficulty: " << recipe.difficulty << "\n"
       << "Portions: " << recipe.portions << "\n"
	   << "Calories: " << recipe.calculate_calories() << "\n"
       << "Products:\n";

    for (const auto& product : recipe.get_product_list_vector()) 
	{
        os << "- " << product << "\n";
    }
    return os;
}

std::ifstream& operator>>(std::ifstream& pointer, Recipe& recipe)
{
	std::string temp1;
	int temp2;

	// Read recipe name
	std::getline(pointer, recipe.name);
	
	// Read number of steps
	std::getline(pointer, temp1);
	temp2 = std::stoi(temp1);

	if (temp2 <= 0)
		throw std::invalid_argument("Check recipes file!");

	// Push steps at steps attribute end
	for (int i=0; i < temp2; i++)
	{
		std::getline(pointer, temp1);
		recipe.steps.push_back(temp1);
	}

	// Read number of products
	std::getline(pointer, temp1);
	temp2 = std::stoi(temp1);

	if (temp2 <= 0)
		throw std::invalid_argument("Check recipes file!");

	// Push products
	for (int i=0; i < temp2; i++)
	{
		std::getline(pointer, temp1);
		recipe.product_list.push_back(Product(temp1));
	}

	// Read prepare time
	std::getline(pointer, temp1);
	temp2 = std::stoi(temp1);
	recipe.prepare_time = temp2;

	// Read difficulty
	std::getline(pointer, temp1);
	temp2 = std::stoi(temp1);
	recipe.difficulty = temp2;
	// Read portions
	std::getline(pointer, temp1);
	temp2 = std::stoi(temp1);
	recipe.portions = temp2;

	return pointer;
}

bool Recipe::operator==(const Recipe& other) const
{
	return (this->name == other.get_name());
}

bool Recipe::operator!=(const Recipe& other) const
{
	return !(*this == other);
}