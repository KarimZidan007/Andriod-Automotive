#include <iostream>
#include "car.hpp"

int main()
{
    Car Car_one("BMW", "X6", 2024);
    std::cout << Car_one.get_company() << std::endl;
    std::cout << Car_one.get_model() << std::endl;
    std::cout << Car_one.get_year() << std::endl;
    Car_one.Set_company("Mercedes");
    Car_one.Set_model("C180");
    Car_one.Set_year(2024);
    std::cout << Car_one.get_company() << std::endl;
    std::cout << Car_one.get_model() << std::endl;
    std::cout << Car_one.get_year() << std::endl;
    return 0;
}
