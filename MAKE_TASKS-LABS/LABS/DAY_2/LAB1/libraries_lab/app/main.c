#include <stdio.h>
#include <math.h>
#include "addition.h"
#include "subtraction.h"
#include "modulus.h"
#include "multiplication.h"
#include "division.h"




int main() {
    char operator;
    float num1, num2;
    double result;

    printf("Enter operator (+, -, *, /, %%):\n");
    scanf("%c", &operator);

    printf("Enter two numbers:\n");
    scanf("%f %f", &num1, &num2);

    switch(operator) {
        case '+':
           result = add(num1,num2);
            break;
        case '-':
            result = sub(num1,num2);
            break;
        case '*':
            result = multiplication(num1,num2);
            break;
        case '/':
            if(num2 == 0)
            {
                printf("ERROR! num2 can't be zero\n");
            }
            else
            { 
                result = division(num1,num2);
            }
            break;
        case '%':
            result = modulus(num1,num2);
            break;
        default:
            printf("Error! Invalid operator.\n");
            return 1; 
    }

    printf("Result: %.2lf\n", result);
    
    return 0;
}
