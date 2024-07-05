##Running the Examples
To run these examples, you'll need a terminal and "make" installed. For each example, put the contents in a file called Makefile, and in that directory run the command make. Let's start with the simplest of Makefiles:

```bash
hello:
	echo "Hello, World"
```

Note: Makefiles must be indented using TABs and not spaces or make will fail.

Here is the output of running the above example:

```bash
$ make  
echo "Hello, World"
Hello, World
```
##Makefile Syntax

A Makefile consists of a set of rules. A rule generally looks like this:


```bash
targets:prerequisities 
    command
    command
```
The targets are file names, separated by spaces. Typically, there is only one per rule.

The commands are a series of steps typically used to make the target(s). These need to start with a tab character, not spaces.

The prerequisites are also file names, separated by spaces. These files need to exist before the commands for the target are run. These are also called dependencies



```bash
hello:
	echo "Hello, World"
	echo "This line will print if the file hello does not exist."
```

There's already a lot to take in here. Let's break it down:

We have one target called hello
This target has two commands
This target has no prerequisites
We'll then run make hello. As long as the hello file does not exist, the commands will run. If hello does exist, no commands will run.

It's important to realize that I'm talking about hello as both a target and a file. That's because the two are directly tied together. Typically, when a target is run (aka when the commands of a target are run), the commands will create a file with the same name as the target. In this case, the hello target does not create the hello file.

##Make clean

clean is often used as a target that removes the output of other targets, but it is not a special word in Make. You can run make and make clean on this to create and delete some_file.

Note that clean is doing two new things here:

It's a target that is not first (the default), and not a prerequisite. That means it'll never run unless you explicitly call make clean
It's not intended to be a filename. If you happen to have a file named clean, this target won't run, which is not what we want. See .PHONY later in this tutorial on how to fix this

```bash
some_file: 
	touch some_file

clean:
	rm -f some_file 
```
##VARIABLES

Variables can only be strings. You'll typically want to use :=, but = also works.

```bash
files := file1 file2
some_file: $(files)
	echo "Look at this variable: " $(files)
	touch some_file

file1:
	touch file1
file2:
	touch file2

clean:
	rm -f file1 file2 some_file
```
##Targets

Making multiple targets and you want all of them to run? Make an all target. Since this is the first rule listed, it will run by default if make is called without specifying a target.

```bash

all: one two three

one:
	touch one
two:
	touch two
three:
	touch three

clean:
	rm -f one two three
```
##Multiple targets

When there are multiple targets for a rule, the commands will be run for each target. $@ is an automatic variable that contains the target name.

```bash

all: f1.o f2.o

f1.o f2.o:
	echo $@
# Equivalent to:
# f1.o:
#	 echo f1.o
# f2.o:
#	 echo f2.o

```
##FUNCTIONS

### * Wildcard

Both * and % are called wildcards in Make, but they mean entirely different things. * searches your filesystem for matching filenames. I suggest that you always wrap it in the wildcard function, because otherwise you may fall into  common pitfall described below.

```bash

# Print out file information about every .c file
print: $(wildcard *.c)
	ls -la  $?

```

* may be used in the target, prerequisites, or in the wildcard function.

Danger: * may not be directly used in a variable definitions

Danger: When * matches no files, it is left as it is (unless run in the wildcard function)

```bash
thing_wrong := *.o # Don't do this! '*' will not get expanded
thing_right := $(wildcard *.o)

all: one two three four

# Fails, because $(thing_wrong) is the string "*.o"
one: $(thing_wrong)

# Stays as *.o if there are no files that match this pattern :(
two: *.o 

# Works as you would expect! In this case, it does nothing.
three: $(thing_right)

# Same as rule three
four: $(wildcard *.o)

```

##% Wildcard
% is really useful, but is somewhat confusing because of the variety of situations it can be used in.

When used in "matching" mode, it matches one or more characters in a string. This match is called the stem.



##AUTOMATIC VARIABLES

There are many automatic variables, but often only a few show up:

```bash
hey: one two
	# Outputs "hey", since this is the target name
	echo $@

	# Outputs all prerequisites newer than the target
	echo $?

	# Outputs all prerequisites
	echo $^

	# Outputs the first prerequisite
	echo $<

	touch hey

one:
	touch one

two:
	touch two

clean:
	rm -f hey one two
```
##FANCY RULES

Implicit Rules
Make loves c compilation. And every time it expresses its love, things get confusing. Perhaps the most confusing part of Make is the magic/automatic rules that are made. Make calls these "implicit" rules. I don't personally agree with this design decision, and I don't recommend using them, but they're often used and are thus useful to know. Here's a list of implicit rules:

Compiling a C program: n.o is made automatically from n.c with a command of the form $(CC) -c $(CPPFLAGS) $(CFLAGS) $^ -o $@
Compiling a C++ program: n.o is made automatically from n.cc or n.cpp with a command of the form $(CXX) -c $(CPPFLAGS) $(CXXFLAGS) $^ -o $@
Linking a single object file: n is made automatically from n.o by running the command $(CC) $(LDFLAGS) $^ $(LOADLIBES) $(LDLIBS) -o $@
The important variables used by implicit rules are:

CC: Program for compiling C programs; default cc
CXX: Program for compiling C++ programs; default g++
CFLAGS: Extra flags to give to the C compiler
CXXFLAGS: Extra flags to give to the C++ compiler
CPPFLAGS: Extra flags to give to the C preprocessor
LDFLAGS: Extra flags to give to compilers when they are supposed to invoke the linker
Let's see how we can now build a C program without ever explicitly telling Make how to do the compilation:

CC = gcc # Flag for implicit rules
CFLAGS = -g # Flag for implicit rules. Turn on debug info

```bash
# Implicit rule #1: blah is built via the C linker implicit rule
# Implicit rule #2: blah.o is built via the C compilation implicit rule, because blah.c exists
blah: blah.o

blah.c:
	echo "int main() { return 0; }" > blah.c

clean:
	rm -f blah*

```
##Static Pattern Rules

```bash
targets...: target-pattern: prereq-patterns ...
   commands
```
The essence is that the given target is matched by the target-pattern (via a % wildcard). Whatever was matched is called the stem. The stem is then substituted into the prereq-pattern, to generate the target's prereqs.

```bash
objects = foo.o bar.o all.o
all: $(objects)
	$(CC) $^ -o all

foo.o: foo.c
	$(CC) -c foo.c -o foo.o

bar.o: bar.c
	$(CC) -c bar.c -o bar.o

all.o: all.c
	$(CC) -c all.c -o all.o

all.c:
	echo "int main() { return 0; }" > all.c

# Note: all.c does not use this rule because Make prioritizes more specific matches when there is more than one match.
%.c:
	touch $@

clean:
	rm -f *.c *.o all

```


here is the effecient way

##Command Echoing/Silencing
Add an @ before a command to stop it from being printed
You can also run make with -s to add an @ before each line

##Command Execution

Each command is run in a new shell (or at least the effect is as such)

```bash
all: 
	cd ..
	# The cd above does not affect this line, because each command is effectively run in a new shell
	echo `pwd`

	# This cd command affects the next because they are on the same line
	cd ..;echo `pwd`

	# Same as above
	cd ..; \
	echo `pwd`
```
##Default Shell
The default shell is /bin/sh. You can change this by changing the variable SHELL:

```bash
SHELL=/bin/bash

cool:
	echo "Hello from bash"

```

##Double dollar sign

If you want a string to have a dollar sign, you can use $$. This is how to use a shell variable in bash or sh.

Note the differences between Makefile variables and Shell variables in this next example.

```bash
make_var = I am a make variable
all:
	# Same as running "sh_var='I am a shell variable'; echo $sh_var" in the shell
	sh_var='I am a shell variable'; echo $$sh_var

	# Same as running "echo I am a make variable" in the shell
	echo $(make_var)

```

# Run this with "export shell_env_var='I am an environment variable'; make"
```
all:
	# Print out the Shell variable
	echo $$shell_env_var

	# Print out the Make variable
    echo $(shell_env_var)
```

##Error handling with -k, -i, and -

Add -k when running make to continue running even in the face of errors. Helpful if you want to see all the errors of Make at once.
Add a - before a command to suppress the error
Add -i to make to have this happen for every command.


###There are two flavors of variables:

recursive (use =) - only looks for the variables when the command is used, not when it's defined.
simply expanded (use :=) - like normal imperative programming -- only those defined so far get expanded

```bash
# Recursive variable. This will print "later" below
one = one ${later_variable}
# Simply expanded variable. This will not print "later" below
two := two ${later_variable}

later_variable = later

all: 
	echo $(one)
	echo $(two)

```


```bash
Simply expanded (using :=) allows you to append to a variable. Recursive definitions will give an infinite loop error.

one = hello
# one gets defined as a simply expanded variable (:=) and thus can handle appending
one := ${one} there

all: 
	echo $(one)


```

conclusion := will expand and will not look at the whole program if one is defined before it will expand else will not



##INPUT FROM OUTERSHELL
```bash
all:
        echo ${KAREM}
        echo $${KAREM}
```

```bash
outer shell

 make
echo 50
50
echo ${KAREM}
50


```
${KAREM} substitute the GLOBAL SHELL VARIABLE

##define directive  
define/endef simply creates a variable that is set to a list of commands. Note here that it's a bit different than having a semi-colon between commands, because each is run in a separate shell, as expected.

##Target a Specific var


```bash 


all: one = cool

all: 
	echo one is defined: $(one)

other:
	echo one is nothing: $(one)

```


##Pattern-specific variables

```bash
%.c: one = cool

blah.c: 
	echo one is defined: $(one)

other:
	echo one is nothing: $(one)


```

##Check if a variable is defined

```bash

bar =
foo = $(bar)

all:
ifdef foo
	echo "foo is defined"
endif
ifndef bar
	echo "but bar is not"
endif

```
##Functions

Functions are mainly just for text processing. Call functions with $(fn, arguments) or ${fn, arguments}. Make has a decent amount of builtin functions.

```bash 
bar := ${subst not,"totally", "I am not superman"}
all: 
	@echo $(bar)

```

```bash 
If you want to replace spaces or commas, use variables

comma := ,
empty:=
space := $(empty) $(empty)
foo := a b c
bar := $(subst $(space),$(comma),$(foo))

all: 
	@echo $(bar)

```

##The vpath Directive

Use vpath to specify where some set of prerequisites exist. The format is vpath <pattern> <directories, space/colon separated> <pattern> can have a %, which matches any zero or more characters. You can also do this globallyish with the variable VPATH

```bash
vpath %.h ../headers ../other-directory

# Note: vpath allows blah.h to be found even though blah.h is never in the current directory
some_binary: ../headers blah.h
	touch some_binary

../headers:
	mkdir ../headers

# We call the target blah.h instead of ../headers/blah.h, because that's the prereq that some_binary is looking for
# Typically, blah.h would already exist and you wouldn't need this.
blah.h:
	touch ../headers/blah.h

clean:
	rm -rf ../headers
	rm -f some_binary

```


##.phony

Adding .PHONY to a target will prevent Make from confusing the phony target with a file name. In this example, if the file clean is created, make clean will still be run. Technically, I should have used it in every example with all or clean, but I wanted to keep the examples clean. Additionally, "phony" targets typically have names that are rarely file names, and in practice many people skip this.

```bash
some_file:
	touch some_file
	touch clean

.PHONY: clean
clean:
	rm -f some_file
	rm -f clean
```


##VPATH

```bash
vpath %.h ./INCLUDES
vpath %.c ./src

a.out: a.o b.o
        gcc $^ -o $@ 

a.o: main.c
        gcc -I./INCLUDES -c $< -o $@
b.o: add.c
        gcc -I./INCLUDES -c $< -o b.o

.phony: clean

clean:
        rm *.o *.out

```
