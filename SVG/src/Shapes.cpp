#include "Shapes.hpp"
#include <iostream>


//  class Rect : public BaseShape


void Rect::set_width(const std::string width)
{
    this->width = width;
}

void Rect::set_height(const std::string height)
{
    this->height = height;
}

void Rect::set_stroke(const std::string stroke)
{
    this->stroke = stroke;
}

std::string Rect::get_svg_format() const
{
    return 
    (
        "<rect x=\"" +
        this->placement.first + 
        "\" y=\"" +
        this->placement.second +
        "\" width=\"" +
        this->width +
        "\" height=\"" +
        this->height +
        "\" " + 
        "fill=\"" + 
        this->color +
        "\" stroke=\"" +
        this->stroke + 
        "\"/>"
    );
}

void Rect::load_from_console_shape()
{
    this->load_from_console_base();

    std::cout << "Enter width:" << std::endl;
    std::cin >> this->width;

    std::cout << "Enter height:" << std::endl;
    std::cin >> this->height;

    std::cout << "Enter stroke" << std::endl;
    std::cin >> this->stroke;
}


//  class Circle : public BaseShape


std::string Circle::get_svg_format() const
{
    return 
    (
        "<circle cx=\"" +
        this->placement.first + 
        "\" cy=\"" +
        this->placement.second +
        "\" r=\"" +
        this->radius +
        "\" fill=\"" + 
        this->color +
        "\" />"
    );

}

void Circle::load_from_console_shape()
{
    this->load_from_console_base();

    std::cout << "Enter radius:" << std::endl;
    std::cin >> this->radius;
}


//  class Text : public BaseShape


std::string Text::get_svg_format() const
{
    return 
    (
        "<text x=\"" +
        this->placement.first + 
        "\" y=\"" +
        this->placement.second +
        "\" font-size=\"" +
        this->font_size +
        "\" text-anchor=\"" +
        this->text_anchor +
        "\" fill=\"" + 
        this->color +
        "\" >" +
        this->text + 
        "</text>"
    );

}

void Text::load_from_console_shape()
{
    this->load_from_console_base();

    std::cout << "Enter font size:" << std::endl;
    std::cin >> this->font_size;

    std::cout << "Enter text anchor:" << std::endl;
    std::cin >> this->text_anchor;

    std::cout << "Enter text::" << std::endl;
    std::cin >> this->text;
}


//  class Line : public BaseShape



std::string Line::get_svg_format() const
{
    return 
    (
        "<line x1=\"" +
        this->placement.first + 
        "\" y1=\"" +
        this->placement.second +
        "\" x2=\"" +
        this->end.first +
        "\" y2=\"" +
        this->end.second +
        "\" " + 
        "style=\"stroke:" + 
        this->color +
        ";stroke-width:" +
        this->width + 
        "\"/>"
    );

}

void Line::load_from_console_shape()
{
    this->load_from_console_base();

    std::cout << "Enter x2 coordinate:" << std::endl;
    std::cin >> this->end.first;

    std::cout << "Enter y2 coordinate:" << std::endl;
    std::cin >> this->end.second;

    std::cout << "Enter width:" << std::endl;
    std::cin >> this->width;
}
