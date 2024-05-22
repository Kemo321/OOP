#include "Image.hpp"
#include <iostream>


Image::Image(std::string html_filename, std::string width, std::string height)
{  
    this->size.first = width;
    this->size.second = height;
    try
    {
        this->file.push_back(File(html_filename));
    }
    catch (...)
    {
        throw (std::exception("Cannot create Image files"));
    }
}

void Image::show_shapes()
{
    int i = 0;

    for (const std::unique_ptr<BaseShape>& ptr : this->shapes)
    {
        std::cout << i + 1 << ". " << ptr->name() << std::endl;
    }
}

int Image::get_length() const
{
    return this->shapes.size();
}

std::string Image::get_svg_format() const
{
    std::string format = 
        "<svg version=\"1.1\" \n width=\"" + 
        this->size.first +
        "\" height=\"" + 
        this->size.second + 
        "\"" + "\n" + 
        "xmlns=\"http://www.w3.org/2000/svg\">" +
        "\n";
    
    for (const std::unique_ptr<BaseShape>& ptr : this->shapes)
    {
        format += ptr->get_svg_format() + "\n";
    }

    format += "</svg>";

    return format;
}

void Image::add_shape(std::unique_ptr<BaseShape> shape)
{
    this->shapes.push_back(std::move(shape));
}

void Image::remove_shape(int index)
{
    this->shapes.erase(this->shapes.begin() + index - 1);
}

std::ostream& operator<<(std::ostream& os, Image& image)
{
    os << image.get_svg_format();

    return os;
}
