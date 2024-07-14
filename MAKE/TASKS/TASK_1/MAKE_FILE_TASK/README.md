#Compiling and Linking Using Makefile

This repository includes a Makefile that automates the compilation and linking process for the project. Follow these steps to build the project:

##Prerequisites

Before compiling the project, ensure you have the following installed:

- **GCC**: GNU Compiler Collection
- **Make**: Build automation tool

##Compilation Steps

1. **Clone the Repository:**

   ```bash
   git clone <repository_url>
   cd <repository_directory>
##Review the Makefile:

Open Makefile in your preferred text editor to understand the available targets and variables.

##Compile the Project:

To compile the project, simply run:

```bash

make App.out
```

This command will invoke the Makefile, compile all source files (*.c) into object files (*.o), and then link them into an executable named App.out, which will be placed in the build directory.\

##Cleaning Up

To clean up generated object files and the executable, run:

```bash 
make clean
```
This command will remove all .o files from the bin directory and the App.out executable from the build directory.





