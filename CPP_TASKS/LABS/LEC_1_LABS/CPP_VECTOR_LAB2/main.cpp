#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Define the VECTOR structure
struct VECTOR {
    unsigned int *Vector;   // Dynamic array
    unsigned int SIZE;      // Maximum size of the vector
    unsigned int CAPACITY;  // Current number of elements in the vector
};

// Define enumeration for STATE
typedef enum {
    FALSE,  // Indicates a failed state
    TRUE    // Indicates a successful state
} STATE;

// Define enumeration for SHIFT types
typedef enum {
    INSERT_SHIFT,  // Shift type for inserting elements
    DELETE_SHIFT   // Shift type for deleting elements
} SHIFT;

// Function declarations
STATE INIT_DARRAY(struct VECTOR *vector1);
STATE INSERT_ELEMENT(struct VECTOR *vector1, unsigned int element, unsigned int POSITION);
void SHIFT_VEC(struct VECTOR *vec, unsigned int start_pos, SHIFT shift_type);
STATE IS_VEC_FULL(struct VECTOR *vec1);
STATE EXTENDING_VECTOR(struct VECTOR *vector);
void DELETING(struct VECTOR *vector1, unsigned POSITION);
void DISPLAY_VECTOR(struct VECTOR *vec);
void INSERTING(struct VECTOR *vector1, unsigned int element, unsigned POSITION);

int main() {
    struct VECTOR vector1;

    // User inserts size
    printf("ENTER THE SIZE OF DYNAMIC ARRAY \n");
    scanf("%i", &vector1.SIZE);

    // Initialize the VECTOR
    STATE state = INIT_DARRAY(&vector1);

    // Testing sequence
    // Insert at the beginning
    INSERT_ELEMENT(&vector1, 1, 1);
    // Insert at the end
    INSERT_ELEMENT(&vector1, 2, 2);
    INSERT_ELEMENT(&vector1, 3, 3);
    // Insert at a specific position
    INSERT_ELEMENT(&vector1, 10, 2); // capacity +1 = size
    // Display the whole vector elements
    DISPLAY_VECTOR(&vector1);
    // Delete at a specific position
    DELETING(&vector1, 2);
    // Display vector elements
    DISPLAY_VECTOR(&vector1);

    return 0;
}

/**
 * @brief Initialize the dynamic array (VECTOR)
 * 
 * @param vector1 Pointer to the VECTOR structure
 * @return STATE Returns TRUE if initialization is successful, otherwise FALSE
 */
STATE INIT_DARRAY(struct VECTOR *vector1) {
    STATE STATUS = FALSE;
    // Dynamic allocation for vector based on user size
    vector1->Vector = (unsigned int *)malloc(sizeof(unsigned int) * vector1->SIZE);
    if (NULL == vector1->Vector) {
        printf("EXCEPTION");
    } else {
        STATUS = TRUE;
    }
    // Initialize capacity to 0 at the beginning
    vector1->CAPACITY = 0;

    return STATUS;
}

/**
 * @brief Insert an element into the VECTOR at a specified position
 * 
 * @param vector1 Pointer to the VECTOR structure
 * @param element Element to be inserted
 * @param POSITION Position to insert the element (1-based index)
 * @return STATE Returns TRUE if insertion is successful, otherwise FALSE
 */
STATE INSERT_ELEMENT(struct VECTOR *vector1, unsigned int element, unsigned int POSITION) {
    STATE STATUS = FALSE;
    // Check if vector is full
    STATUS = IS_VEC_FULL(vector1);
    if (TRUE == STATUS) {
        // If VEC FULL call the extend function (extend size *2)
        unsigned int EXTEND_STATE = EXTENDING_VECTOR(vector1);
        if (TRUE == EXTEND_STATE) {
            // If extending is performed right then insert the element
            INSERTING(vector1, element, POSITION);
        } else {
            printf("EXTENDING VECTOR FAILED \n");
        }
    } else if (FALSE == STATUS) {
        // If vector is not full insert element directly
        INSERTING(vector1, element, POSITION);
    }

    return STATUS;
}

/**
 * @brief Check if the VECTOR is full
 * 
 * @param vec1 Pointer to the VECTOR structure
 * @return STATE Returns TRUE if the VECTOR is full, otherwise FALSE
 */
STATE IS_VEC_FULL(struct VECTOR *vec1) {
    STATE status = TRUE;
    if (vec1->CAPACITY == vec1->SIZE) {
        status = TRUE;
    } else if (vec1->CAPACITY < vec1->SIZE) {
        status = FALSE;
    }

    return status;
}

/**
 * @brief Shift elements in the VECTOR to make space or remove an element
 * 
 * @param vec Pointer to the VECTOR structure
 * @param start_pos Position to start shifting from (1-based index)
 * @param shift_type Type of shift (INSERT_SHIFT or DELETE_SHIFT)
 */
void SHIFT_VEC(struct VECTOR *vec, unsigned int start_pos, SHIFT shift_type) {
    if (INSERT_SHIFT == shift_type) {
        for (unsigned int i = vec->CAPACITY; i > start_pos - 1; i--) {
            vec->Vector[i] = vec->Vector[i - 1];
        }
    } else if (DELETE_SHIFT == shift_type) {
        for (unsigned int i = start_pos - 1; i < vec->CAPACITY - 1; i++) {
            vec->Vector[i] = vec->Vector[i + 1];
        }
    }
}

/**
 * @brief Display the elements of the VECTOR
 * 
 * @param vec Pointer to the VECTOR structure
 */
void DISPLAY_VECTOR(struct VECTOR *vec) {
    for (unsigned int i = 0; i < vec->CAPACITY; i++) {
        printf("%i\t", vec->Vector[i]);
    }
    printf("\n");
}

/**
 * @brief Insert an element into the VECTOR at a specified position
 * 
 * @param vector1 Pointer to the VECTOR structure
 * @param element Element to be inserted
 * @param POSITION Position to insert the element (1-based index)
 */
void INSERTING(struct VECTOR *vector1, unsigned int element, unsigned POSITION) {
    // Vector is not full and can insert
    if ((POSITION <= vector1->SIZE) && (POSITION - 1 == vector1->CAPACITY)) {
        // Insert at end
        vector1->Vector[POSITION - 1] = element;
        vector1->CAPACITY++;
    } else if ((POSITION <= vector1->SIZE) && (POSITION < vector1->CAPACITY)) {
        // Shift because of inserting in the middle of vector
        SHIFT_VEC(vector1, POSITION, INSERT_SHIFT);
        // Then insert element at the position
        vector1->Vector[POSITION - 1] = element;
        vector1->CAPACITY++;
    }
}

/**
 * @brief Extend the size of the VECTOR
 * 
 * @param vector Pointer to the VECTOR structure
 * @return STATE Returns TRUE if extension is successful, otherwise FALSE
 */
STATE EXTENDING_VECTOR(struct VECTOR *vector) {
    STATE extending_state = FALSE;
    vector->Vector = (unsigned int *)realloc(vector->Vector, (vector->SIZE * 2) * sizeof(unsigned int));
    if (NULL == vector->Vector) {
        extending_state = FALSE;
    } else {
        extending_state = TRUE;
        vector->SIZE *= 2;
    }
    return extending_state;
}

/**
 * @brief Delete an element from the VECTOR at a specified position
 * 
 * @param vector1 Pointer to the VECTOR structure
 * @param POSITION Position to delete the element from (1-based index)
 */
void DELETING(struct VECTOR *vector1, unsigned POSITION) {
    if ((POSITION <= vector1->SIZE) && (POSITION == vector1->CAPACITY)) {
        vector1->Vector[POSITION - 1] = 0;
        vector1->CAPACITY--;
    } else if ((POSITION <= vector1->SIZE) && (POSITION < vector1->CAPACITY)) {
        // Shift because of deleting in the middle of vector
        SHIFT_VEC(vector1, POSITION, DELETE_SHIFT);
        vector1->CAPACITY--;
    }
}

