# Dynamic Array Implementation in C

This repository contains an implementation of a dynamic array in C. The implementation provides functionalities for initializing, inserting, deleting, extending, and displaying elements in the array.

## Structure and Enumerations

### `struct VECTOR`
The `VECTOR` structure defines a dynamic array with the following members:
- `unsigned int *Vector`: Pointer to the dynamic array.
- `unsigned int SIZE`: Maximum size of the vector.
- `unsigned int CAPACITY`: Current number of elements in the vector.

### `STATE` Enumeration
Defines the state of operations:
- `FALSE`: Indicates a failed state.
- `TRUE`: Indicates a successful state.

### `SHIFT` Enumeration
Defines the type of shift operation:
- `INSERT_SHIFT`: Shift type for inserting elements.
- `DELETE_SHIFT`: Shift type for deleting elements.

## Functions

### `STATE INIT_DARRAY(struct VECTOR *vector1)`
Initializes the dynamic array based on the user-defined size.

### `STATE INSERT_ELEMENT(struct VECTOR *vector1, unsigned int element, unsigned int POSITION)`
Inserts an element at a specified position in the vector.

### `STATE IS_VEC_FULL(struct VECTOR *vec1)`
Checks if the vector is full.

### `void SHIFT_VEC(struct VECTOR *vec, unsigned int start_pos, SHIFT shift_type)`
Shifts elements in the vector for insertion or deletion.

### `void DISPLAY_VECTOR(struct VECTOR *vec)`
Displays the elements of the vector.

### `void INSERTING(struct VECTOR *vector1, unsigned int element, unsigned POSITION)`
Helper function to insert elements into the vector.

### `STATE EXTENDING_VECTOR(struct VECTOR *vector)`
Extends the size of the vector when it is full.

### `void DELETING(struct VECTOR *vector1, unsigned POSITION)`
Deletes an element from the vector at a specified position.

## Usage

### Compilation
To compile the program, use the following command:
```sh
g++ -o dynamic_array main.cpp

