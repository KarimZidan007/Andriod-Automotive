# iti Lab

### Objective:

Create a Makefile and Bash script to compile and link a calculator application. The application should support both static and dynamic linking.

#### Steps to Write the Makefile:

- Define the compiler to use.
- Specify the necessary directories and include paths.
- Define the source and object files for your application and libraries.
- Create rules to compile the source files into object files and place them into obj directory
- Create rules to build both static and dynamic libraries from the object files and place each lib into a directory
- Create rules to link the application with both the static and dynamic libraries.
- Include a clean target to remove all generated files and directories.

#### Write the Bash Script:

- Create a script to automate the build process.
- Check if the required arguments (target and compiler) are provided.
- Set the compiler based on the provided argument.
- Use a case statement to handle different build targets: static, dynamic, and clean.
- Call the corresponding Makefile targets based on the user input.
- Provide usage instructions and error messages for invalid arguments.

---

### Hints:

#### Makefile:

- Use $(wildcard $(SRC_DIR)/*.c) to list all .c files in the src directory.
- Use $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(DYNAMIC_LIB_SRC)) to generate object file names.
- Use -I to include the header files directory.
- Use -shared to create a dynamic library and ar rcs to create a static library.
- Use -L to specify the library directory and -l to link the library.

#### Bash Script:

- Use $1 and $2 to access the script arguments.
- Use case statements to handle different targets.
- Ensure the script is executable using chmod +x.
