#include <iostream>
#include <initializer_list>

/*
Implement a class for a dynamic array (Vector)
    * Containing the following functions
        * resize() - resize the array to double the size
        * pushback(value) - add the value to the end of the array
        * popback() - remove the last element from the array
        * removeAt(index) - remove the element at the given index
        * insertAt(index, value) - insert the value at the given index and shift the elements to the right
        * insertMiddle(value) - insert the value in the middle of the array
        * removeMiddle() - remove the middle element from the array
        * size() - return the size of the array
        * print() - print the array

    * The following overload constructors:
        * DynamicArray() - default constructor with capacity of 1
        * DynamicArray(size) - constructor with given capacity
        * DynamicArray(size, value) - constructor with given capacity and initial value for all elements --> DynamicArray arr(5, 10);
        * DynamicArray(size, values) - constructor with given capacity and initial values --> DynamicArray arr(5, new int[5]{1, 2, 3, 4, 5});
        * DynamicArray(arr) - copy constructor

    * Appropriate destructor

    - Private members:
        * array - pointer to the array
        * capacity - capacity of the array
        * currentSize - current size of the array

*/

enum STATE
{
    FALSE,
    TRUE
};
enum SHIFT
{
    INSERT_SHIFT,
    DELETE_SHIFT
};

template <typename T>
class DynamicArray
{
private:
    T *vector;
    unsigned int Max_Size;
    unsigned int Current_Size;

    void SHIFT_VEC(unsigned int start_pos, SHIFT shift_type)
    {
        if (INSERT_SHIFT == shift_type)
        {
            for (unsigned int i = (Current_Size); i > start_pos; i--)
            {
                vector[i] = vector[i - 1];
            }
        }

        else if (DELETE_SHIFT == shift_type)
        {
            for (unsigned int i = start_pos - 1; i < Current_Size - 1; i++)
            {
                vector[i] = vector[i + 1];
            }
        }
    }
    STATE IS_VEC_FULL()
    {
        STATE status = FALSE;
        if (Current_Size == Max_Size)
        {
            status = TRUE;
            status = resize();
        }
        else if (Current_Size < Max_Size)
        {
            status = FALSE;
        }

        return status;
    }
    STATE resize()
    {
        STATE extending_state = FALSE;
        T *vector_temp = new T[Max_Size * 2];
        for (unsigned int i = 0; i < Max_Size; i++)
        {
            vector_temp[i] = this->vector[i];
        }
        delete[] this->vector;
        Max_Size *= 2;
        extending_state = TRUE;

        this->vector = vector_temp;

        return extending_state;
    }

public:
    DynamicArray() : Max_Size{1}, Current_Size{0}
    {
        vector = new T[Max_Size];
    }
    DynamicArray(unsigned int Size) : Current_Size{0}
    {
        Max_Size = Size;
        vector = new T[Max_Size];
    }
    // DynamicArray(size, values) - constructor with given capacity and initial values --> DynamicArray arr(5, new int[5]{1, 2, 3, 4, 5});

    DynamicArray(unsigned int Size, std::initializer_list<T> Arr) : Max_Size{Size}
    {
        vector = new T[Max_Size];
        Current_Size = 0;
        for (T i : Arr)
        {

            vector[Current_Size] = i;
            this->Current_Size++;
        }
    }
    // DynamicArray(size, value) - constructor with given capacity and initial value for all elements --> DynamicArray arr(5, 10);
    DynamicArray(unsigned int Size, T value)
    {
        Max_Size = Size;
        vector = new T[Max_Size];
        for (int i = 0; i < Max_Size; i++)
        {
            vector[i] = value;
            Current_Size++;
        }
    }
    DynamicArray(const DynamicArray &D_Array)
    {
        this->Max_Size = D_Array.Max_Size;
        this->vector = new T[this->Max_Size];
        for (int i = 0; i < Max_Size; i++)
        {
            this->vector[i] = D_Array.vector[i];
            Current_Size++;
        }
    }
    // resize() - resize the array to double the size

    STATE pushback(T element)
    {
        STATE operation_state = FALSE;
        vector[Current_Size++] = element;
        operation_state = TRUE;
        return operation_state;
    }
    // popback() - remove the last element from the array
    STATE popback(T *element)
    {
        STATE operation_state = FALSE;
        *element = vector[Current_Size - 1];
        Current_Size--;
        operation_state = TRUE;
        return operation_state;
    }
    // removeAt(index) - remove the element at the given index
    STATE removeAt(unsigned int index)
    {
        STATE operation_state = FALSE;
        if ((index > Max_Size) || (index < 0))
        {

            STATE operation_state = FALSE;
        }
        else
        {
            if (Current_Size == index) // at the end
            {
                Current_Size--;
                operation_state = TRUE;
            }
            else // remove and shift
            {
                SHIFT_VEC(index, DELETE_SHIFT);
                Current_Size--;
                operation_state = TRUE;
            }
        }
        return operation_state;
    }
    // insertAt(index, value) - insert the value at the given index and shift the elements to the right
    STATE insertAt(unsigned int index, T element)
    {
        STATE operation_state = FALSE;
        operation_state = IS_VEC_FULL();

        if (Current_Size == index)
        {
            // insert at end
            vector[index] = element;
            Current_Size++;
            operation_state = TRUE;
        }
        else if (index > Current_Size)
        {
            std::cout << "vector still has places this index not sequental" << std::endl;
            operation_state = FALSE;
        }
        else if (index < Current_Size)
        {
            SHIFT_VEC(index, INSERT_SHIFT);
            vector[index] = element;
            Current_Size++;
            operation_state = TRUE;
        }

        return operation_state;
    }

    // insertMiddle(value) - insert the value in the middle of the array
    STATE insertMiddle(T element)
    {
        STATE operation_state = FALSE;
        unsigned int index = ((Current_Size + 1) / 2);
        operation_state = insertAt(index, element);
        return operation_state;
    }
    // removeMiddle() - remove the middle element from the array
    STATE removeMiddle()
    {
        STATE operation_state = FALSE;
        unsigned int index = ((Current_Size + 1) / 2);
        operation_state = removeAt(index);
        return operation_state;
    }
    // size() - return the size of the array
    unsigned int Size()
    {
        std::cout << "Current Size is : " << Max_Size << std::endl;
        return Current_Size;
    }

    // print() - print the array
    void print()
    {
        for (int i = 0; i < Current_Size; i++)
        {
            std::cout << "index : " << i << " is " << vector[i] << std::endl;
        }
        std::cout << "-----------------------------------------" << std::endl;
    }
};
int main()
{
    float x;
    DynamicArray<float> Vec(5, {10.5, 20.2, 30.3, 40.9, 50.1});
    Vec.print();
    Vec.insertAt(5, 99.5);
    Vec.popback(&x);
    Vec.insertMiddle(88);
    Vec.print();
    Vec.removeMiddle();
    Vec.Size();
    Vec.print();
}
