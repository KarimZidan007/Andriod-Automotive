## File system 

i want to notifey kernel that root file system is on Partition2

there is an shared variable called **bootargs** on U-boot


to make kernel mount 

 mount -t ext4 /dev/mmcblk0p2 / 

root=/dev/mmcblk0p2 rw


also to say that i want to display on this 

console=/dev/ttyO or /dev/tty0 -> rpi 

console =/dev/AMA0 -> qemu


## creating an application 


1. make an application and cross compile it 


2. 

![1](1.png)


pass the rootfile system

```sh

console=ttyAMA0,38400n8 root=/dev/mmcblk0p2 rw

```


then add init

```sh

console=tty0 console=ttyAMA0,38400n8 root=/dev/mmcblk0p2 rw init=/

```

3. run bootcmd 


![1](2.png)
 

4. i want now to download a set of commands using busybox

![1](3.png)


5. 

```sh
make menuconfig

```
![1](4.png)


6. choose required commands 


7. 

```sh

make install

```
8. then under install_ i will get a rootfs arch for the output 

9. so i will make my own filesystem and copy the data on it 

10. 

a- dev/ - sys/ - proc/  -> use mount  

b- make usr/bin -> copy from install_ 
   usr/sbin-> copy from install_ 
   usr/lib -> sysroot



c-  mount -t sysfs sys 
    mount -t proc proc 
    mount -t devtmpfs /dev




11. so what about making a script like the first process ever and set all of the following 

a. first one was busybox init  

init process is at **/sbin/init** -> it parse configuration from **/etc/inittab**

configuration i wiret it by my self 

syntax is 

```sh
node::action::Application to run


```
types of Actions 

1. Sysint -> what happen first 
2. Wait  -> run application and wait for completion
3. Once ->run application but does not wait for completion
4. respond -> read about it 
5. askfirst -> propmt messege before running (ask me first)
6. ctrl+alt+del -> make a specific action when you press that 
5. shutdown -> close application
6. 


```sh
node :: actio ::Application to run 
::Sysinit:/usr/bin/mount -t (devtemps) /dev
::Sysinit:/usr/bin/mount -t (sysfs) /sys

```

**output will be in install_**

## busybox TC 

vim .config 

search for /CONFIG_TC 

## init does not appear 

make it executable

make soft link for commands that already here 

busybox make it by default make softlink for busybox for every command on /bin 

- create inittab

::sysinit:/etc/init.d/rcs -> rcs (run command start)
::askfirst:/bin/sh

i will make the a script make the above mount rcs 
mount the sys init 

then on bootarg init=/sbin/init


**sequence**
1. after i made init=/sbin/init -> parse /etc/init.d/rcs -> it will mount then -> it will askuser first to open shell so i will find the changes


## steps
1. mount sd card 
2. mkdir -p bin sbin usr/bin usr/sbin  usr/lib /etc/init.d dev sys proc 
3. hack command  rsync  -a ~/busybox/_install  ~/media/sdcard 
4. rsync -a ~/x-tool/arm/sysroot -> libraries that i build for musl or libcc i need it 
5. then i will editenv bootarg (init) or if i use efi partition i will use APPEND   


## initramfs 

this used for recovery mood  

_install i have to compile install on static way 



i will take bin sbin usr  

so for size i will take the essential commands (mount ls mdsum ) ->compression (cpio) on x86 or host -> and set it on /boot  

   
now /boot -> dtb , uboot ,zImage , extlinux/extlinux.conf , u-boot.env 

## ADVANTAGES 

1. faster
2. used in bootloader double bank to switch to another bank if i update my firmware 
3. i could make it as boot manager i boot to it first and then choose which partitionn i will boot 
4. for security -> checksum for the partition before i boot to it to ensure that there is no manipulation 
5. used in recoverymood in kernel that grub make options to boot into it 

i want to say to u-boot to boot on 
1. initrd=/bin/sh -> init proc for the initramfs 

or

2. init=/bin/init -> for my main root file system 

then load it to ram using 

```sh
fatload -> to any address away from ram 

bootz $kernel $initramfs $dtb 

- was the initramfs
 
if i remove - and initramfs will boot on rfs normally 
```

1. after i make commands and scripts cpio then and fatload to ram   
2. i will boot on it -> mount the partition that i will switch to it 
3. then i will change root i will use chroot to switch to the 


i want initramfs -> make c script scanf if 1 make action if 2 make action  (so i want to open file then execute) 
if 1 i will boot from partition 1 if 2 partition 2 and change root 


(FINAL TASK AFTER NEGOTIATION)
----------------------

i will add /etc/inittab on ramfs 
and init=/sbin/init which will parse inittab 

/etc/inittab 
::sysiint:init.d/rcs

inside rcs 
read - p ,which partition 

switch(var) 

mount the partition
chroot(to rfs)


----------------------


if i used INITRD -> give it the initramdisk -> init (proc or rootfile) 

----------------------

if i want to add user 

adduser 

and i have to create /etc/passwd , /etc/shadow /etc/group  


creating user before my system loads 

fady:x:1000:1000:  /home/fady  /bin/sh 

----------------------
NETWORK FILESYSTEM (nfs)

access filesystem on a server 

if i write ls -> it will get fetch server and get it then i will execute it on my ram  

```sh
#on x86
sudo apt install nfs-kernel-server 

there is a file /etc/exports  

3- /srv/nfs  client ip (192.168.0.2) rw 

4- export -r or restart nfs server 

```
5- editenv bootargs root=/dev/nfs -> client use the interface that attached to the nfs server  192.18.0.1 (server ip)

why nfs is important 
on developing phase with out insert and out the usb or sd card use the nfs to test an application on run time 


![1](5.png)


to boot on initramfs -> static busybox -> compiled static 


