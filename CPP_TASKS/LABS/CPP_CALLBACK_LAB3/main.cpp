#include <stdio.h>
#include <stdlib.h>

// Define a function pointer type for functions that take a pointer to int and an int, and return an int
typedef int(*PtrToFunc)(int *, int);

// Function prototype for Add
int Add(int *, int);

// Define a function pointer type for functions that take a 2D array, row size, array of column sizes, and a function pointer
typedef int *(*CallbackFunc)(int **, int, int *, PtrToFunc);

// Function prototype for ArrayAddRow
int* ArrayAddRow(int **, int, int *, PtrToFunc);

int main() {
    // Define three arrays of different sizes
    int arr1[3] = {1, 2, 3};
    int arr2[5] = {1, 2, 3, 4, 5};
    int arr3[4] = {1, 2, 3, 4};
    
    // Number of rows in the 2D array
    int rows = 3;
    
    // Create a 2D array using the three arrays defined above
    int *_2dArr[] = {arr1, arr2, arr3};
    
    // Array containing the number of columns for each row
    int columns[] = {3, 5, 4};
    
    // Define a function pointer and assign it to ArrayAddRow
    CallbackFunc pointertofunc = ArrayAddRow;
    
    // Call the function through the function pointer and get the result
    int *sumptr = pointertofunc(_2dArr, rows, columns, Add);
    
    // Print the sum of elements in each row
    for (int i = 0; i < rows; i++) {
        printf("arr[%d] = [%d]\n", i, sumptr[i]);
    }
    
    // Deallocate memory
    free(sumptr);
    
    return 0;
}

// Function to add all elements of an array
int Add(int *arr, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

// Function to create an array of sums of each row in a 2D array
int* ArrayAddRow(int **arr, int rows, int *columns, PtrToFunc Addptr) {
    // Allocate memory for the result array
    int *SumArray = (int*)malloc(sizeof(int) * rows);
    
    // Calculate the sum of each row and store it in the result array
    for (int i = 0; i < rows; i++) {
        SumArray[i] = Addptr(arr[i], columns[i]);
    }
    
    return SumArray;
}

