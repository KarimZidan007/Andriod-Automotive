# PACKAGE MANAGER

1. collection of files
2. dpkg -i -> de pack
3. dpkg -l -> list the files 
## APT
APT (Advanced Package Tool) in Linux is a command-line tool used for managing software packages. It handles installation, updating, upgrading, and removal of software on Debian-based distributions like Ubuntu. Common commands include:

apt update: Updates the package list.
apt upgrade: Upgrades all installed packages.
apt install <package>: Installs a specified package.
apt remove <package>: Removes a specified package.
apt autoremove: Removes unnecessary packages.
APT simplifies software management by resolving dependencies and automating tasks.

APT is a server host all packages with it is dependencies 
apt install -> down then install
upgrade-> download new version 
update -> fetch new updates on server
## snap 
consume more size because apt check for already available dependcies and download the rest but snap download all

## archivig 
```bash
tar -cf (bag name).tar file 1 file2 ...

c-> create
f-> output name

file commmand is used to know the extension for a file 

```

## extracting
 
```bash
tar -xf (bagname) /dir
x extract
```

```bash
gzip  -> gunzip file.tar.gzip -> decompress  , gzip file [to be compressed]
xz -> unxz
bzipz -> bzip2-d ->decompressed
are implemented alghorithim
```

## USER

1. NORMAL USER
 ID between [1000-40000]    
2. SYSTEM USER
 ID between[1-199]   
- one of it is responsiblity when i connect through ssh ssh system user the one who receive and send ssh to userspace (NORMAL USER) because system user is more secured ->  zidan -> system user called ssh -> kernel 
3. SERVICE USER[200-999]

I NEED TO LEARN WHAT IS THE DIFF BETWEEN SYS USER - NORMAL USERs


/etc/passwod ->users
1. zidan:x:1001:1001:,,,:/home/zidan:/bin/bash
2. NAME:UID:GID:Comment:homedirect:shelltype
/etc/shadow -> passwords encrypted on one way encryption



## GROUP
cat /etc/group

all groups are here

how to add a group 
```bash

groupadd
Add user groups to the system.See also: groups, groupdel, groupmod.More information: https://manned.org/groupadd.

 - Create a new group:
   sudo groupadd {{group_name}}

 - Create a new system group:
   sudo groupadd --system {{group_name}}

 - Create a new group with the specific groupid:
   sudo groupadd --gid {{id}} {{group_name}}

```
sudo visudo -> here i could edit on groups has root privilage 




## full process 
1. add user -> adduser (user)
2. then i found it on /etc/passwd
3. i add a group -> groupadd (group name)
4. then i opened /etc/sudors -> i add %sudo =All(All:All)All -> all user all groups , all applications 
5. %groupname =All(All:All)All
6. then add the user to the group -> /etc/group -> my user:x:22:(set here the newuser)
7. sudo command go parse the file of sudors and check that the user belong to any group who has that privllages
8. usermod -ag group and hero


## i can not make hardlink a cross two devices because every device has it is device addresses ( part1 start from 0x00 and also part2 start from 0x00)

1. hardlink -> it poits to the i node of the origin file
2. symblic link -> it creates a new i node contain the same meta data of the origin file 
