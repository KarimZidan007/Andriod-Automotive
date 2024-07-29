#include <iostream>
#include <vector>
#include <algorithm> // Include this header for std::for_each
#include <stdexcept>

class Base
{
public:
    virtual double divide(double numerator, double denominator)
    {
        if (denominator == 0)
        {
            throw std::runtime_error("Base class: Division by zero is not allowed.");
        }
        return numerator / denominator;
    }
};




int main()
{

    try
    {
        float sum = divide(5, 0);
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << '\n';
    }

    return 0;
}