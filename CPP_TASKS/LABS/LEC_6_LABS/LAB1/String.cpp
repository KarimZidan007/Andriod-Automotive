#include <iostream>
#include <string>
int main()
{
    std::string text = "The cycle of life is a cycle of cycles";
    std::string Wordtoreplace = "cycle";
    std::string replacment_word = "circle";

    int position;
    position = text.find(Wordtoreplace);

    while (std::string::npos != position)
    {
        text.replace(position, Wordtoreplace.length(), replacment_word);
        position = text.find(Wordtoreplace, position + replacment_word.length());
    }
    text.insert(4, "great ");

    int position_two = 0;
    std::cout << text << std::endl;
    int n = 0;
    while (n != 2)
    {
        position_two = text.find(replacment_word, position_two + replacment_word.length());
        std::cout << position_two << std::endl;

        if (position_two != std::string::npos)
        {
            n++;
            std::cout << "n is :" << n << std::endl;
        }
    }

    text.insert(position_two, "never-ending ");
    std::cout << text << std::endl;

    return 0;
}
