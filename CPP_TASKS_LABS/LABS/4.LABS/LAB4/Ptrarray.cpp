#include <iostream>
#include <string>
#include <typeinfo>
#include <variant>

using ValueType = std::variant<int, double, char>;

class VPointerArray
{
private:
    void **ptr;
    unsigned int Size;

public:
    std::string *ptr_dt;

    VPointerArray(unsigned int Size)
    {
        this->Size = Size;
        ptr = new void *[Size];
        ptr_dt = new std::string[Size];
    }

    void Set_Value(auto *value, unsigned int index)
    {
        if (index < Size)
        {
            ptr[index] = value;
            ptr_dt[index] = static_cast<std::string>(typeid(value).name());
        }
        else
        {
            std::cout << "INVALID INDEX \n"
                      << std::endl;
        }
    }

    ValueType Get_Value(unsigned int index)
    {
        int *VAL_1;
        double *VAL_2;
        char *VAL_3;

        if (index < Size)
        {
            if ((ptr_dt)[index] == "Pi")
            {
                VAL_1 = (int *)(ptr[index]);
                // std::cout<<"INT"<<(*VAL_1)<<std::endl;
                return *VAL_1;
            }

            else if ((ptr_dt)[index] == "Pd")
            {
                VAL_2 = (double *)(ptr[index]);
                // std::cout<<"double  "<<(*VAL_2)<<std::endl;
                return *VAL_2;
            }

            else if ((ptr_dt)[index] == "Pc")
            {
                VAL_3 = (char *)(ptr[index]);
                // std::cout<<"char"<<VAL_3<<std::endl;
                return *VAL_3;
            }
        }
        else
        {
            std::cout << "INVALID INDEX \n"
                      << std::endl;
        }

        return {};
    }
    unsigned int Get_Size()
    {
        return this->Size;
    }
    void Get_DataType(unsigned int index)
    {

        std::cout << "Type of ptr[" << index << "]: " << ptr_dt[index] << std::endl;

        std::cout << ptr_dt[index] << std::endl;
    }

    void print(void)
    {

        for (int i = 0; i < this->Size; i++)
        {
            auto x = this->Get_Value(i);
            process_value(x);
        }
    }

    ValueType Type_Check(unsigned int index)
    {
    }

    ~VPointerArray()
    {
        delete[] ptr;
    }
    void process_value(const ValueType &value)
    {
        std::visit([](auto &&arg)
                   { std::cout << "Value: " << arg << std::endl; }, value);
    }
};

int main()
{

    int value = 5;
    double value1 = 55.5;
    char value2 = 'k';
    VPointerArray Array1(3);
    Array1.Set_Value((int *)&value, 0);
    Array1.Set_Value((double *)&value1, 1);
    Array1.Set_Value((char *)&value2, 2);

    // get the value by just set the index we want and then process it
    auto value11 = Array1.Get_Value(1);
    Array1.process_value(value11);
    // print all values
    Array1.print();
    return 0;
}
