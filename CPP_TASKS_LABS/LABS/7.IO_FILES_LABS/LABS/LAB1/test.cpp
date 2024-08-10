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
    // open the file F_INPUT as input (read ) , out (write) , app (append) modes
    file_input.open("F_INPUT.txt", std::ios::in | std::ios::out | std::ios::app);
    //read the first line of the file on the str var
    std::getline(file_input, str);
    // convert str into integer and load it on max , min variables

    Min = Max = std::stoi(str);
    //return back the file pointer to the beginning of the file 
    file_input.seekg(0, std::ios::beg);
    //read the file line by line
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
