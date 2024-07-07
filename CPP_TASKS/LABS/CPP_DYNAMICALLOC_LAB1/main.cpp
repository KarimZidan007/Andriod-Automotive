#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE_NAME 20
int NUMBER_OF_STRINGS;

// Function prototypes
void CREATE_ARRAY_OF_STRINGS(char ***ptr1);
void PRINT_STRINGS(char **ptr1);
void GET_USER_STRINGS(char *buffer, char **ptr1);

int main() {
    // Declarations
    char **ptr1 = NULL;
    char buffer[MAX_SIZE_NAME];

    // Input number of strings from user
    printf("ENTER NUMBER OF STRINGS\n");
    scanf("%d", &NUMBER_OF_STRINGS);

    // Allocate memory for array of strings
    CREATE_ARRAY_OF_STRINGS(&ptr1);

    // Get strings from user input
    GET_USER_STRINGS(buffer, ptr1);

    // Print all strings entered by user
    PRINT_STRINGS(ptr1);

    // Free allocated memory
    for (int i = 0; i < NUMBER_OF_STRINGS; i++) {
        free(ptr1[i]);
    }
    free(ptr1);

    return 0;
}

// Function to allocate memory for array of strings
void CREATE_ARRAY_OF_STRINGS(char ***ptr1) {
    *ptr1 = (char **)malloc(sizeof(char *) * NUMBER_OF_STRINGS);
    if (*ptr1 == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < NUMBER_OF_STRINGS; i++) {
        (*ptr1)[i] = (char *)malloc(sizeof(char) * MAX_SIZE_NAME);
        if ((*ptr1)[i] == NULL) {
            printf("Memory allocation failed.\n");
            exit(EXIT_FAILURE);
        }
    }
}

// Function to print all strings stored in ptr1
void PRINT_STRINGS(char **ptr1) {
    for (int i = 0; i < NUMBER_OF_STRINGS; i++) {
        printf("%s\n", ptr1[i]);
    }
}

// Function to get strings from user input and store them in ptr1
void GET_USER_STRINGS(char *buffer, char **ptr1) {
    for (int i = 0; i < NUMBER_OF_STRINGS; i++) {
        scanf("%s", buffer);
        strcpy(ptr1[i], buffer);
        memset(buffer, 0, sizeof(buffer)); // Clear buffer for next input
    }
}
