#pragma once
#include <string>


class File
{
protected:

    std::string filename;

public:
    File(const std::string filename);

    std::string get_content() const;

    void write(std::string content) const;

    bool file_exists() const;
};