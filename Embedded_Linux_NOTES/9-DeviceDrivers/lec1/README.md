## kernel receive data from user 

- so i will use write syscall there is a parameter called (const char --user *buffer) 

- i can not make dereference of this buffer because it is pagging 

- so how to get it ? 

copy_from_user(dest,source,size) 



## types of devicedrivers

1. charachter (gpio-uart..etc)

2. block device (storge)

3. network device

--------------
char devices 

- each device in system has an id of 32 bis 


12 bit Major_N - 20 bit Minor_N

dev_t mydev_id;
 set it here 


char buffer[BUFF_SIZE]; -> minor
char buffer2[BUFF_SIZE]; ->mahor 

how to allocate ID ?

by a function provided bykernel 

alloc_chrdev_region(address that gonna hold the id (type dev_t),base_n(start number of the dev like mmc0),number ofdevices responsible by this driver,"drivername")


MAJOR NUMBER -> DRIVER 

MINOR NUMBER -> DEVICES 


what make the file of device under /dev ? 

using service mknod file name (char)

or manualy 

class_create("iti_class");
