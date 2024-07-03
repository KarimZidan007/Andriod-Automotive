# Stack Buffer Overflow

This repository demonstrates what a stack buffer overflow is, how it occurs, and how to mitigate it using safe programming practices.

## Table of Contents

- [Introduction](#introduction)
- [What is a Stack Buffer Overflow?](#what-is-a-stack-buffer-overflow)
- [Code Example of a Stack Buffer Overflow](#code-example-of-a-stack-buffer-overflow)
- [Consequences of Stack Buffer Overflow](#consequences-of-stack-buffer-overflow)
- [Mitigations](#mitigations)
- [Safe Code Example](#safe-code-example)
- [Conclusion](#conclusion)

## Introduction

A stack buffer overflow is a type of buffer overflow that occurs in the stack memory area of a process. It happens when a program writes more data to a buffer located on the stack than the buffer was allocated to hold. This can lead to unpredictable behavior, including crashes, data corruption, and security vulnerabilities.

## What is a Stack Buffer Overflow?

### Stack Memory

The stack is a region of memory used for function call management, including local variables, return addresses, and function parameters.

### Buffer

A buffer is a contiguous block of memory reserved for storing data.

### Overflow

Overflow occurs when data exceeds the allocated space for the buffer.

## Code Example of a Stack Buffer Overflow

Consider a simple example in C where a fixed-size buffer is used to store user input:

```c
#include <stdio.h>
#include <string.h>

void vulnerable_function() {
    char buffer[10]; // Fixed-size buffer
    printf("Enter some text: ");
    gets(buffer); // Unsafe function that doesn't check input length
}

int main() {
    vulnerable_function();
    return 0;
}
```
In this example:

The buffer is allocated 10 bytes on the stack.

The gets function reads input from the user into buffer without checking if the input fits into buffer.

If the user inputs more than 10 characters, the excess characters will overwrite adjacent stack memory, potentially including:

-Other local variables

-The function's return address

-Function parameters

## Consequences of Stack Buffer Overflow

### Crash:
The program may crash if critical data is overwritten.

### Data Corruption :
Variables may hold incorrect values if their memory is

### Mitigations
Use Safe Functions: Prefer safe functions that check buffer lengths, such as fgets instead of gets, or strncpy instead of strcpy.

Stack Canaries: Modern compilers and operating systems use stack canaries, which are special values placed on the stack that help detect overflows.

Address Space Layout Randomization (ASLR): Randomizes memory addresses to make it more difficult for attackers to predict the location of specific memory areas.

Data Execution Prevention (DEP): Marks certain areas of memory as non-executable to prevent execution of malicious code injected via buffer overflows.

### Safe Code Example

```c
#include <stdio.h>
#include <string.h>

void safe_function() {
    char buffer[10]; // Fixed-size buffer
    printf("Enter some text: ");
    fgets(buffer, sizeof(buffer), stdin); // Safe function that checks input length
}

int main() {
    safe_function();
    return 0;
}

```
### Conclusion

Understanding stack buffer overflows is crucial for writing secure code. By using safe functions and following best practices, developers can mitigate the risks associated with buffer overflows and protect their applications from potential vulnerabilities.
