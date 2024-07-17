#include <iostream>
#include <vector>
#include <cstdlib> // For std::rand() and std::srand()
#include <ctime>   // For std::time()
#include <random>  // For std::default_random_engine and std::uniform_int_distribution

class Battleship
{
private:
    std::vector<std::vector<int>> VECT;
    int Current_Guesses;
    int Max_Guesses;
    int X_GUESS, Y_GUESS;
    int X_LOCATION, Y_LOCATION;

    void fill_vect_false(void)
    {
        for (unsigned int row = 0; row < 5; row++)
        {
            for (unsigned column = 0; column < 5; column++)
            {
                VECT[row][column] = 0;
            }
        }
    }

public:
    Battleship(int Max_Guesses) : VECT(5, std::vector<int>(5))

    {
        this->Max_Guesses = Max_Guesses;
        Current_Guesses = 0;
        fill_vect_false();
        Generate_new_place();
    }

    bool Guess()
    {
        bool status = false;

        while (!Game_Over())
        {
            Take_aPoint();

            if ((X_GUESS == X_LOCATION) || (Y_GUESS == Y_LOCATION))
            {
                if (VECT[Y_GUESS][X_GUESS] == 1)
                {
                    std::cout << VECT[Y_LOCATION][X_LOCATION] << std::endl;
                    status = true;
                    std::cout << "Congratulation " << "\n";
                    End_Game();
                    continue;
                }
                else if ((X_GUESS == X_LOCATION))
                {
                    std::cout << "Correct X-Axis only  :" << "\n";
                    status = false;
                }
                else if (Y_GUESS == Y_LOCATION)
                {
                    std::cout << "Correct Y-Axis only  :" << "\n";
                    status = false;
                }
            }

            if ((X_GUESS == (X_LOCATION - 1)) || (X_GUESS == (X_LOCATION + 1)))
            {
                std::cout << "You are close -> X-Axis  :" << "\n";
                status = false;
            }
            else if ((Y_GUESS == (Y_LOCATION - 1)) || (Y_GUESS == (Y_LOCATION + 1)))
            {
                std::cout << "You are on Close -> Y-Axis  :" << "\n";
                status = false;
            }
            else
            {
                std::cout << "Wrong Guess \n";
                status = false;
            }
            Current_Guesses++;
            std::cout << "your Current Guesses is : " << Get_Guesses() << "\n ";
        }

        return status;
    }

    bool Game_Over()
    {
        bool status = false;

        if (Current_Guesses >= Max_Guesses)
        {
            VECT[Y_LOCATION][X_LOCATION] = 0;
            End_Game();

            status = true;
        }

        else
        {
            status = false;
        }
        return status;
    }

    int Get_Guesses()
    {
        return Current_Guesses;
    }
    void End_Game()
    {
        int decision = 0;
        std::cout << "GAME OVER -_- " << "\n";
        std::cout << "Play Again ?  1-> Yes 2->No " << "\n";
        std::cin >> decision;
        if (decision == 1)
        {
            Current_Guesses = 0;
            this->fill_vect_false();
            Generate_new_place();
        }
        else
        {
            std::cout << "Thank You for Playing" << "\n";
        }
    }
    void Take_aPoint()
    {
        std::cout << "Enter X-point Y-point \n";
        std::cin >> this->X_GUESS >> this->Y_GUESS;
    }
    void Generate_new_place(void)
    {
        fill_vect_false();
        std::srand(static_cast<unsigned int>(std::time(0)));
        // Generate a random number between 0 and 4
        int random_row = std::rand() % 5;
        int random_column = std::rand() % 5;
        VECT[random_row][random_column] = 1;
        this->X_LOCATION = random_column;
        this->Y_LOCATION = random_row;
        // Output the generated random number
    }

    void display(void)
    {
        for (auto i : VECT)
        {
            std::cout << "row : " << " data is : \t";

            for (auto value : i)
            {
                std::cout << value << "\t";
            }
            std::cout << "\n";
        }
    }
};

int main()
{
    Battleship Game(5);
    Game.Guess();

    return 0;
}