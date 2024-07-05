## Question 1: List three Linux Distributions.
1. Ubuntu
2. Fedora
3. CentOS

## Question 2: From the slides, what is the `man` command used for?
The `man` command in Linux is used to display the manual pages of a given command. It provides detailed information about the command's syntax, options, and usage.

## Question 3: What is the difference between `rm` and `rmdir` using the `man` command?
- `rm`: Removes files or directories. If used with the `-r` option, it can remove directories and their contents recursively.
- `rmdir`: Removes empty directories. It cannot remove directories that contain files or other directories.

## Question 4: Create the following hierarchy under your home directory and answer the sub-questions.

### a. Remove `dir11` with `rmdir` in one step. What did you notice? And how did you overcome that?
Removing `dir11` using `rmdir` returns an error that the directory is not empty. To solve this issue, use `rm -rf dir11`.

### b. Remove `OldFiles` using `rmdir -p` command. State what happened to the hierarchy.
The command returned "no such file or directory."

### c. The output of the command `pwd` was `/home/user`. Write the absolute and relative path for the file `mycv`.
- Absolute Path: `/home/karimzidan/docs`
- Relative Path: `docs/mycv`

## Question 5: Copy the `/etc/passwd` file to your home directory.

```bash
cp /etc/passwd ~
```
##Question 6: Rename this new file to be oldpasswd.

```bash
mv ~/passwd ~/oldpasswd
```


##Question 7: You are in /usr/bin, list four ways to go to your home directory.



```bash
cd ~
cd /home
cd $HOME
cd -
cd
```


##Question 8: List Linux commands in /usr/bin that start with the letter w.


```bash
ls w*
```

##Question 9: What are type commands used for? (from the slide)


1-Alias command: Executes before anything else.

2-Internal command: A command that is part of the shell itself and does not have to be loaded from disk separately.

3-External command: A command that exists as an executable file on the disk of the computer.


##Question 10: Show two types of command files in /usr/bin that start with the letter c.


1-Built-in command starting with c: cd

2-External command: cmp


##Question 11: Using the man command, find the command to read a file.


```bash
man cat
```

##Question 12: What is the usage of the apropos command?

The apropos command helps the user when they don’t remember the exact command but know a few keywords related to the command that define its uses or functionality. It searches the Linux man page with the help of the keyword provided by the user to find the command and its functions.

```bash
apropos -e mkdir
```


