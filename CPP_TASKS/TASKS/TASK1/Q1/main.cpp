#include <iostream> // Include the iostream library for input and output operations

using namespace std;

int main() {
    int result = 0; // Variable to store the cumulative sum of the numbers
    int number = 0; // Variable to store the user input number

    while (1) { // Infinite loop
        cout << "Please Enter Number\n"; // Prompt user to enter a number (Note: The prompt should ideally ask for a number)
        cin >> number; // Read the user input and store it in the variable 'number'

        if (0 != number) { // Check if the input number is not zero
            result += number; // Add the input number to the cumulative sum 'result'
        } else { // If the input number is zero
            cout << "result is :" << result << "\n"; // Output the cumulative sum 'result'
            break; // Exit the loop
        }
    }

    return 0; // Return 0 to indicate successful execution of the program
}

