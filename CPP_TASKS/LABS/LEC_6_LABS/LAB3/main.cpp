#include <iostream>
#include <vector>

std::vector<std::vector<int>> VEC_2D = {{1, 2, 3, 22}, {4, 5, 6, 11}, {7, 8, 9, 33}};
std::vector<std::vector<int>> &Transpose(std::vector<std::vector<int>> &VECTOR);

int main()
{

    Transpose(VEC_2D);
    return 0;
}

std::vector<std::vector<int>> &Transpose(std::vector<std::vector<int>> &VECTOR)
{
    unsigned int row_size = VECTOR.size();
    unsigned int column_size = VECTOR[0].size();
    unsigned int columnshift = 0, row_shift = 0;
    // init a new vector
    std::vector<std::vector<int>> NEW_VEC(column_size, std::vector<int>(row_size));

    for (auto it : VECTOR)
    {

        for (auto val : it)
        {

            NEW_VEC[row_shift][columnshift] = val;
            row_shift++;
        }
        columnshift++;
        row_shift = 0;
    }
    columnshift = 0;

    for (auto it : NEW_VEC)
    {

        for (auto val : it)
        {

            std::cout << val << "\t";
        }
        std::cout << "\n";
    }
}
