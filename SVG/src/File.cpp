#include "File.hpp"
#include <fstream>
#include <iostream>
#include <string>
#include <filesystem>


File::File(const std::string filename)
{
    this->filename = filename;
}

std::string File::get_content() const
{
    if (!file_exists())
    {
        std::cerr << "File doesnt exist" << std::endl;
        return "";
    }

    std::ifstream is(this->filename);

    if (!is.is_open())
    {
        std::cerr << "File exists but can not be opened" << std::endl;
        return "";
    }

    std::string content;

    std::string line;

    while (std::getline(is, line))
    {
        content += line + "\n";
    }

    return content;
}

void File::write(std::string content) const
{
    std::ofstream is(this->filename);

    if (!is.is_open())
    {
        std::cerr << "File cannot be created or opened" << std::endl;
        return;
    }

    is << content;

    return;
}

bool File::file_exists() const
{
    return std::filesystem::exists(this->filename);
}
