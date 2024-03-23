#include "Date.h"
#include <iostream>

Date::Date(int day, int month, int year)
{
    if (this->check_date(day, month, year))
    {
            this->day = day;
            this->month = month;
            this->year = year;
    }
    else
        throw std::invalid_argument("Incorrect date");
};

int Date::get_day() const
{
    return this->day;
};

void Date::set_day(const int new_day)
{
    try
    {
        if (this->check_date(new_day, this->month, this->year))
        {
            this->day = new_day;
        }
        else 
            throw std::invalid_argument("Incorrect day");
    }
    catch(const std::invalid_argument& e)
    {
    std::cerr << e.what() << std::endl;
    }
};

int Date::get_month() const
{
    return this->month;
};

void Date::set_month(const int new_month)
{
    try
    {
        if (this->check_date(this->day, new_month, this->year))
        {
            this->month = new_month;
        }
        else 
            throw std::invalid_argument("Incorrect month");
    }
    catch(const std::invalid_argument& e)
    {
    std::cerr << e.what() << std::endl;
    }
    
};

int Date::get_year() const
{
    return this->year;
};

void Date::set_year(const int new_year)
{
    try
    {
        if (new_year >= 0)
            this->year = new_year;
        else
            throw std::invalid_argument("Incorrect year");
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
};

std::string Date::calculate_day_name(int day, int month, int year) const
{
    // Zeller's Congruence algorithm
    if (month < 3)
    {
        month += 12;
        year--;
    }

    int k = year % 100;
    int j = year / 100;

    int day_index = (day + ((13 * (month + 1)) / 5) + k + (k / 4) + (j / 4) - (2 * j)) % 7;
    day_index = (day_index + 7) % 7;

    return this->day_name[day_index];
};

std::string Date::get_formatted_date(const int format) const
{
    std::string formatted_date;
    switch(format)
    {
        case 1:
        {
            formatted_date = (std::to_string(this->day) + "/" + std::to_string(this->month) + "/" + std::to_string(this->year));
            break;
        };
        case 2:
        {
            formatted_date = (std::to_string(this->day) + "/" + this->length_of_each_month[this->month - 1].second + "/" + std::to_string(this->year));
            break;
        };
        case 3:
        {
            std::string name_of_the_day = calculate_day_name(this->day, this->month, this->year);
            formatted_date = (name_of_the_day + " " + std::to_string(this->day) + "." + std::to_string(this->month) + "." + std::to_string(this->year));
            break;
        };
        default:
        {
            formatted_date = "Invalid date format chosen";
            break;
        }
    }
    return formatted_date;
};

bool Date::check_date(const int day, const int month, const int year) const
{
    return(
        year >= 0 &&
        month > 0 &&
        month < 13 &&
        day > 0 &&
        (day <= this->length_of_each_month[month - 1].first
        ||
        day == 29 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        )
    );
}

bool Date::operator==(const Date& other) const 
{
    return (this->day == other.get_day() && this->month == other.get_month() && this->year == other.get_year());
}


bool Date::operator>(const Date& other) const 
{
    return !(*this <= other);
}

bool Date::operator<(const Date& other) const 
{
    return (this->year < other.get_year() || this->year == other.get_year() && this->month < other.get_month()) || 
    (this->year == other.get_year() && this->month == other.get_month() && this->day <= other.get_day());
}

bool Date::operator<=(const Date& other) const
{
    return (this->operator==(other) || this->operator<(other));
}

bool Date::operator>=(const Date& other) const
{
    return !(*this < other);
}