#include "BaseShape.hpp"
#include <iostream>

BaseShape::BaseShape() 
{
    this->load_from_console_shape();
}

std::string BaseShape::name() const
{
    return "";
}

std::string BaseShape::get_svg_format() const
{
    return "";
}

void BaseShape::load_from_console_base()
{
    std::cout << "Enter x coordinate:" << std::endl;
    std::cin >> this->placement.first;
    
    std::cout << "Enter y coordinate:" << std::endl;
    std::cin >> this->placement.second;

    std::cout << "Enter color:" << std::endl;
    std::cin >> this->color;
}

void BaseShape::load_from_console_shape()
{
    ;
}

std::ostream& operator<<(std::ostream& os, const std::unique_ptr<BaseShape>& shape)
{
    os << shape->get_svg_format() << std::endl;
    return os;
}

std::string BaseShape::get_x() const
{
    return this->placement.first;
}

std::string BaseShape::get_y() const
{
    return this->placement.second;
}
    
std::string BaseShape::get_color() const
{
    return this->color;
}

void BaseShape::set_placement(const std::pair<std::string, std::string> new_placement)
{
    this->placement.first = new_placement.first;
    this->placement.second = new_placement.second;
}

void BaseShape::set_color(const std::string color)
{
    this->color = color;
}