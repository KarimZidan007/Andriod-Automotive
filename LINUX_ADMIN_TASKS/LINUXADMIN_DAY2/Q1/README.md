# Binary Search Algorithm in C

This project contains an implementation of a binary search algorithm in C. The binary search algorithm efficiently searches for a value in a sorted array by repeatedly dividing the search interval in half.

## Function Description

### `BinarySearchAlgorithm`

The `BinarySearchAlgorithm` function searches for a specified value within a sorted array and returns the index of the value if found. If the value is not found, it returns -1.

#### Function Prototype

```c
int BinarySearchAlgorithm(int Data[], int Req_Value);
```

## Parameters
Data[]: An array of integers, which must be sorted in ascending order.
Req_Value: The value to search for within the array.

## Return Value
The index of Req_Value in the Data array if found.
-1 if Req_Value is not found in the Data array.

Example Usage
```c
#include <stdio.h>

#define DATA_MAX_SIZE 10

int BinarySearchAlgorithm(int Data[], int Req_Value) {
    int M_Index, S_Index = 0;
    int E_Index = (DATA_MAX_SIZE - 1);

    while (S_Index <= E_Index) {
        M_Index = S_Index + ((E_Index - S_Index) / 2);

        if (Req_Value == Data[M_Index]) {
            return M_Index;
        } else if (Req_Value > Data[M_Index]) {
            S_Index = M_Index + 1;
        } else {
            E_Index = M_Index - 1;
        }
    }

    return -1;
}

int main() {
    int MyData[DATA_MAX_SIZE] = {0, 11, 22, 33, 44, 55, 66, 77, 88, 99};
    unsigned int index = 0;

    index = BinarySearchAlgorithm(MyData, 55);
    printf("FOUND ON INDEX %d \n", index);

    return 0;
}



```
## Compilation and Execution
```bash
gcc -o binary_search binary_search.c
./binary_search
```

## Sample Output
```bash

FOUND ON INDEX 5

```


