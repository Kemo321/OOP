#include "Image.hpp"
#include "Shapes.hpp"
#include <iostream>


int main()
{
    std::string option1;

    std::string option2;

    std::string index_str;

    std::string width;

    std::string height;

    int index;

    system("cls");
    std::cout << "Enter image width:" << std::endl;
    std::cin >> width;
    std::cout << "Enter image height:" << std::endl;
    std::cin >> height;

    Image image("../../image.html", width, height);

    while (true)
    {
        while (true)
        {
            system("cls");
            std::cout << "Choose an option:" << std::endl;
            std::cout << "0. Exit program" << std::endl;
            std::cout << "1. Add shape" << std::endl;
            std::cout << "2. Remove shape" << std::endl;
            std::cin >> option1;
            std::cout << std::endl;

            if (option1=="0")
                goto end;

            if (option1=="1" || option1=="2")
                break;
        }

        if (option1=="1")
            while (true)
            {
                system("cls");
                std::cout << "Choose shape to add:" << std::endl;
                std::cout << "0. exit" << std::endl;
                std::cout << "1. Rectangle " << std::endl;
                std::cout << "2. Circle" << std::endl;
                std::cout << "3. Text" << std::endl;
                std::cout << "4. Line" << std::endl;
                std::cin >> option2;
                if (option2=="0")
                    break;
                system("cls");
                std::cout << std::endl;

                std::unique_ptr<BaseShape> shp;

                if (option2=="1")
                {
                    shp = std::make_unique<Rect>();
                }

                else if (option2=="2")
                {
                    shp = std::make_unique<Circle>();
                }

                else if (option2=="3")
                {
                    shp = std::make_unique<Text>();
                }

                else if (option2=="4")
                {
                    shp = std::make_unique<Line>();
                }
        
                else
                    continue;

                shp->load_from_console_shape();
                image.add_shape(std::move(shp));
                 
            }
        else if(option1=="2")
            while(true)
            {
                system("cls");
                std::cout << "Choose shape to remove:" << std::endl;
                std::cout << "0. exit" << std::endl;
                image.show_shapes();
                std::cin >> option2;
                std::cout << std::endl;
                if (option2=="0")
                    break;
                index = std::stoi(option2);
                if (index < 0 || index > image.get_length())
                    continue;
                image.remove_shape(index - 1);
            }
    }

end:
    image.file[0].write(image.get_svg_format());
    return 0;
}