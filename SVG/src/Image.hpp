#pragma once
#include "BaseShape.hpp"
#include "File.hpp"
#include <vector>


class Image
{
protected:

    std::vector<std::unique_ptr<BaseShape> > shapes;

    std::pair<std::string, std::string> size;

public:
    Image(const std::string html_filename,  const std::string width, const std::string height);

    void show_shapes();

    int get_length() const;

    std::string get_svg_format() const;

    void add_shape(std::unique_ptr<BaseShape> shape);

    void remove_shape(int index);

    friend std::ostream& operator<<(std::ostream& os, Image& image);

    std::vector<File> file;
};