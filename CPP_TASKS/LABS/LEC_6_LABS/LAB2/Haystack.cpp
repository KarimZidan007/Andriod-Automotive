#include <iostream>
std::string &Manuplation(std::string &Source, std::string &needle, std::string &replacement);

std::string haystack, needle, replacement;

int main()
{
    std::cout << "Enter Source String " << std::endl;
    getline(std::cin, haystack);
    std::cout << "Enter NEEDED String " << std::endl;
    getline(std::cin, needle);
    std::cout << "Enter REPLACMENT String " << std::endl;
    getline(std::cin, replacement);
    std::string RES = Manuplation(haystack, needle, replacement);
    std::cout << RES << std::endl;
    return 0;
}

std::string &Manuplation(std::string &Source, std::string &needle, std::string &replacement)
{
    int position;
    position = Source.find(needle);
    Source.replace(position, needle.length(), replacement);
    return Source;
}
