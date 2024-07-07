#include <iostream>
#include <string>
#include <math.h>
#include <ctype.h>
#include <cstring>

namespace MathFunctions
{
    void print(unsigned int Number)
    {
    std::cout<<sqrt(Number)<<std::endl;
    }
}

namespace StringFunctions
{
    void print(const char str[])
    {
        for(int i =0 ; i < strlen(str);i++)
        {
            std::cout << static_cast<char>(toupper(str[i]));
        }
        std::cout<<""<<std::endl;
    }

}

namespace ArrayFunctions
{

    void print(unsigned int * arr,unsigned int size)
    {
    for(int i=2 ; i >=0 ; i--)
    {
    std::cout<<arr[i]<<"\t";
    }
        std::cout<<""<<std::endl;

    }
}

int main()
{
unsigned int Arr[3]={1,2,3};
MathFunctions::print(5);
StringFunctions::print("karem");
ArrayFunctions::print(Arr,3);

return 0;
}

