#include <unordered_map>
#include <string>
#include <utility>

class Date
{
    private:
    int day;
    int month;
    int year;
    const std::pair<int, std::string> length_of_each_month[12]
    {
        {31, "January"},
        {28, "February"},
        {31, "March"},
        {30, "April"},
        {31, "May"},
        {30, "June"},
        {31, "July"},
        {31, "August"},
        {30, "September"},
        {31, "October"},
        {30, "November"},
        {31, "December"}
    };

    const std::string day_name[7]
    {
        "Saturday",
        "Sunday",
        "Monday",
        "Tuesday",
        "Wednesday",
        "Thursday",
        "Friday"
    };

    public:
    Date(int c_day = 1, int c_month = 1, int c_year = 2024);

    int get_day() const;

    void set_day(const int new_day);

    int get_month() const;

    void set_month(const int new_month);

    int get_year() const;

    void set_year(const int new_year);

    std::string calculate_day_name(int day, int month, int year) const;

    std::string get_formatted_date(const int format = 1) const;

    bool check_date(const int day, const int month, const int year) const;

    bool operator==(const Date& other) const;

    bool operator>(const Date& other) const;

    bool operator<(const Date& other) const;

    bool operator<=(const Date& other) const;

    bool operator>=(const Date& other) const;
};
