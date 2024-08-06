#include <iostream>
#include <string>
#include <cmath>
using namespace std;

// Function to convert binary to decimal
int binaryToDecimal(string binary) {
    int decimal = 0;
    int length = binary.length();
    for (int i = 0; i < length; ++i) {
        if (binary[length - i - 1] == '1') {
            decimal += pow(2, i);
        }
    }
    return decimal;
}

// Function to convert decimal to binary
string decimalToBinary(int decimal) {
    string binary = "";
    while (decimal > 0) {
        binary = (decimal % 2 == 0 ? "0" : "1") + binary;
        decimal /= 2;
    }
    return binary.empty() ? "0" : binary;
}

int main() {
    int choice;
    while (true) {
        cout << "Select conversion type:\n";
        cout << "1. Binary to Decimal\n";
        cout << "2. Decimal to Binary\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            string binary;
            cout << "Enter binary number: ";
            cin >> binary;
            int decimal = binaryToDecimal(binary);
            cout << binary << " in binary is " << decimal << " in decimal.\n";
        } else if (choice == 2) {
            int decimal;
            cout << "Enter decimal number: ";
            cin >> decimal;
            string binary = decimalToBinary(decimal);
            cout << decimal << " in decimal is " << binary << " in binary.\n";
        } else if (choice == 3) {
            break;
        } else {
            cout << "Invalid choice. Please try again.\n";
        }
    }
    return 0;
}

