#pragma once
#include <utility>
#include <string>
#include <memory>


class BaseShape
{
protected:

    std::pair<std::string, std::string> placement = {"0", "0"};

    std::string color;

public:
    BaseShape();

    virtual std::string name() const;

    virtual std::string get_svg_format() const;

    void load_from_console_base();

    virtual void load_from_console_shape();

    friend std::ostream& operator<<(std::ostream& os, std::unique_ptr<BaseShape>& shape);

    // Methods for testing

    std::string get_x() const;

    std::string get_y() const;

    std::string get_color() const;

    void set_placement(const std::pair<std::string, std::string> new_placement);

    void set_color(const std::string color);
};
