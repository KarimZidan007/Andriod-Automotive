#include <iostream>
#include <iomanip>
#include <fstream>
int main()
{
    int Sum = 0;
    int Avg = 0, Max = 0, Min = 0, No_Val = 0;
    std::string str;
    std::fstream file_input;
    std::fstream file_output;
    file_input.open("F_INPUT.txt", std::ios::in | std::ios::out | std::ios::app);
    std::getline(file_input, str);
    Min = Max = std::stoi(str);
    file_input.seekg(0, std::ios::beg);
    while (file_input.eof() == false)
    {
        std::getline(file_input, str);
        Sum += std::stoi(str);
        No_Val++;
        if (Min > std::stoi(str))
        {
            Min = std::stoi(str);
        }
        if (Max < std::stoi(str))
        {
            Max = std::stoi(str);
        }
    }
    // std::cout << "  SUM" <<  << "  AVG" << static_cast<float>(Sum / No_Val) << "  MAX IS : " << Max << "   Min is :" << Min << std::endl;
    //  pushing into the output file
    file_output.open("F_OUTPUT.txt", std::ios::in | std::ios::out | std::ios::app);
    file_output << "---------------------------------------------" << std::endl;
    file_output << "|" << std::setw(6) << std::setfill(' ') << "Sum" << std::setw(5) << std::setfill(' ') << "|" << std::setw(6) << std::setfill(' ') << "AVG" << std::setw(5) << std::setfill(' ') << "|" << std::setw(6) << std::setfill(' ') << "Min" << std::setw(5) << std::setfill(' ') << "|" << std::setw(6) << std::setfill(' ') << "Max" << std::setw(5) << std::setfill(' ') << "|" << std::endl;
    file_output << "---------------------------------------------" << std::endl;
    file_output << "|" << std::setw(6) << std::setfill(' ') << Sum << std::setw(5) << std::setfill(' ') << "|" << std::setw(6) << std::setfill(' ') << static_cast<float>(Sum / No_Val) << std::setw(5) << std::setfill(' ') << "|" << std::setw(6) << std::setfill(' ') << Min << std::setw(5) << std::setfill(' ') << "|" << std::setw(6) << std::setfill(' ') << Max << std::setw(5) << std::setfill(' ') << "|" << std::endl;
    file_output << "---------------------------------------------" << std::endl;

    return 0;
}
