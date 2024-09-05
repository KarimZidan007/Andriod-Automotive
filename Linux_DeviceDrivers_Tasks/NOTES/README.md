## type of devices 
1- network 
2-charachter
3- block 




MAJOR NUMBER -> DRIVER 
MINOR -> DEVICE INSTANCE 





i could create device directly with out using create_class to access it 
i will use mknode command , it takes MAJOR AND MINOR which i could get them using printk("%d,MAJOR(dev)) 
MAJOR(dev) and MINOR(dev) 

`mknode -c MAJOR MINOR /dev/(device name)`

what under /dev are nodes not files 

## cdev init -> initialize the struct cdev 

## dev add -> add this data on structure into the memory frame of the block 


## on write function i handled it myself 

-it is not recommended to set gpio or any hardware access inside the write function

- UDEV -> SOFTWARE IMPLEMENTED IN LINUX (SERVICE IN USERSPACE) 

1. read /sys/class/device 

2. takes major-minor and read metadata from it and mknod under /dev (devices) 


## WHAT IS PCI (HARDWARE BUS) 

- detect new HW assigned on the bus  