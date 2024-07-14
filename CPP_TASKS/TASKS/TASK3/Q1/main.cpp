#include <iostream>
#include <cstdlib>
#define RANDOM(min, max) ((std::rand() % ((max) - (min) + 1)) + (min))

struct vertex
{
    int x;
    int y;

    void fill_rand()
    {

        x = getRandomNumberInRange(-100, 100);
        y = getRandomNumberInRange(-100, 100);
    }

private:
    int getRandomNumberInRange(int min, int max)
    {
        return min + (std::rand() % (max - min + 1));
    }
};

int main()

{

    vertex points[5];
    for (int i = 0; i < 5; i++)
    {
        points[i].fill_rand();
        std::cout << "X OF POINT " << i << " : ->" << points[i].x << std::endl;
        std::cout << "Y OF POINT " << i << " : ->" << points[i].y << std::endl;
    }

    return 0;
}