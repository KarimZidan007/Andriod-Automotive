class calculator
{
private:
    char operator_type;
    int Var_1;
    int Var_2;
    int Sum(int Var_one, int Var_two)
    {
        return Var_one + Var_two;
    }
    int Substract(int Var_one, int Var_two)
    {
        return Var_one - Var_two;
    }
    int Multiplication(int Var_one, int Var_two)
    {
        return Var_one * Var_two;
    }
    double Devision(int Var_one, int Var_two)
    {
        return (static_cast<double>(Var_one) / static_cast<double>(Var_two));
    }
    double Power(int Var_one, int Var_two)
    {
        double result = Var_one;
        while (1 != Var_two)
        {
            Var_two--;
            result *= Var_one;
        }
        return result;
    }
    double Square_Root(int Var_one)
    {
        return sqrt(Var_one);
    }

public:
    calculator()
    {
    }
    void Handle_User_Operations(int Var_one, char operator_type, int Var_two = 0)
    {
        switch (operator_type)
        {
        case ('+'):
            std::cout << "SUM RESULT IS :" << Sum(Var_one, Var_two) << std::endl;
            break;
        case ('-'):
            std::cout << "Substract RESULT IS :" << Substract(Var_one, Var_two) << std::endl;
            break;
        case ('*'):
            std::cout << "Multiplication RESULT IS :" << Multiplication(Var_one, Var_two) << std::endl;
            break;
        case ('/'):
            std::cout << "Devision RESULT IS :" << Devision(Var_one, Var_two) << std::endl;
            break;
        case ('^'):
            std::cout << "Power RESULT IS :" << Power(Var_one, Var_two) << std::endl;
            break;
        case ('S'):
            std::cout << "sqrt RESULT IS :" << sqrt(Var_one) << std::endl;
            break;
        default:
            std::cout << "INVALID OPERATOR" << std::endl;
        }
    }
    ~calculator()
    {
    }
};
