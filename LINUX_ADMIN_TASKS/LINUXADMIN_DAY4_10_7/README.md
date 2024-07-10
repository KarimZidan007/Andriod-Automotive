# Linux File Permissions and User Management

Linux file permissions regulate access to files and directories based on three categories: **User**, **Group**, and **Others**. Here’s a concise overview of how permissions work and how to manage users and groups.

## Permission Types

- **Read (`r`)**: Allows viewing file contents.
- **Write (`w`)**: Allows modifying file contents.
- **Execute (`x`)**: Allows executing a file or accessing a directory.

## Symbolic Representation

Permissions are represented in the format: `chmod [ugoa][+-=][rwx] file`

- **`u`**: Owner permissions
- **`g`**: Group permissions
- **`o`**: Others permissions
- **`a`**: All (equivalent to `ugo`)

## Setting Permissions

### Add Permission

```bash
chmod u+r file     # Add read permission for owner
chmod g+w file     # Add write permission for group
chmod o+x file     # Add execute permission for others
```
Remove Permission
```bash

chmod u-r file     # Remove read permission for owner
chmod g-w file     # Remove write permission for group
chmod o-x file     # Remove execute permission for others
```
Set Exact Permissions
```bash

chmod u=rwx file   # Set read, write, and execute for owner
chmod g=rx file    # Set read and execute for group
chmod o=r file     # Set read-only for others
Adding User to Group
To add a user to a group, use usermod command:
```

```bash

sudo usermod -a -G groupname username
Replace groupname with the name of the group and username with the name of the user you want to add.
```
Examples
chmod u+x,g+w,o-r file (Add execute for owner, write for group, and remove read for others)
chmod u=rwx,g=rx,o=r file (Set full permissions for owner, read and execute for group, read-only for others)
This README.md provides essential information on managing Linux file permissions and user groups. Adjust commands as necessary for your specific Linux distribution and file system requirements.



chmod a+x file: Adds execute permission for all users (a for all, +x to add execute).
chmod g-w file: Removes write permission for the group (g for group, -w to remove write).
## Append to a group

sudo usermod -aG groupname username
Explanation:
sudo: Runs the command with superuser privileges, required to modify user settings.
usermod: The command to modify a user account.
-aG:
-a: Append the user to the specified group without removing the user from other groups.
-G: Indicates that the following argument (groupname) specifies the group to which the user (username) should be appended.
groupname: Replace this with the name of the group to which you want to add the user.
username: Replace this with the username of the user you want to add to the group.



## Change Group command
```bash
chgrp (group) (file)
```

## special permission
chown user:group file 

## set user id
with executable file
take the permission of owner by adding stickybit

## set group id 

inheret the group from the top directory


## sticky bit

only owner can delete his own file can not delete others files 


## implementation of special permission


....(set user id)...|| .....(set group id).... || ....(sticky bit)...

chmod 777 myfile -> normal 
if i want to use read wirte permission

chmod 4777 myfile -> if i want set user id 
chmod 1777 myfile -> if i want to set sticky bit

## Process

underfile system -> Proc fs 
all process running in the RAM

priority -20 is higher 
20 is the lowest

## READ ABOUT QNX

## READ ABOUT MONOLITHINC -> LINUX is MONOLITHIC BECUASE IT IS ENTRY POINT IS MAIN
## QNX -> based on MICROSERVICE ->  microkernel-based every process has it is own kernel
