## lets make device driver for gpio

## we want to control two leds  (so we gonna make two files) 

gpio_direction_output()


gpio_set_value()





if i have a file and i made echo 1>file on it 

1. open(file) -> return file decriptor(3) -> related with structered called file -> instance of it (file operations) 

write(3) , driver_write(instance,,)   



when user write echo 1 it passed as user_buffer


/sys/device equal to /sys/class 
- but class are more structured 
- class deals with udev service with notify that there is new dev and it mount it 














ssize_t driver_write(struct file *file, const char __user *userr, size_t count, loff_t *)
{



        printk("Write Called\n");
    char(*value)[3] = NULL;
    int not_copied;

    if (*(int *)file->private_data == 0)
    {
        value = &led1;
        Status = LED1;
    }
    else if (*(int *)file->private_data == 1)
    {
        value = &led2;
        Status = LED2;
    }
    // this function copy from userspace memory to kernel memory because i can not handle this operation by my self
    // if i copy data from user buff to my own buff i need to move all the count data if i cp only 8 out of 9 it will be entered again untill the move all 9
    // this function return

    copy_from_user();

    return 0;
}



    // this function copy from userspace memory to kernel memory because i can not handle this operation by my self
    // if i copy data from user buff to my own buff i need to move all the count data if i cp only 8 out of 9 it will be entered again untill the move all 9
    // this function return

    copy_from_user();









------------------------------------------------------------------------------
char dev


ssize_t driver_write(struct file *file, const char __user *userr, size_t count, loff_t *offs)
{
    printk("the count is %ld , and the offset %lld \n", count, *offs);
    int to_copy, notcopied, copied;
    int space_available = DEVICE_SIZE - *offs;
    if (space_available == 0)
    {
        return count;
    }
    // if space avaiable not enough to push count , so i will get the minimum and just copy the available
    to_copy = min(count, (size_t)space_available);
    notcopied = copy_from_user(device + *offs, userr, to_copy);
    copied = to_copy - notcopied;
    *offs += copied;

    return copied;
}
























-------------------------------------------------------


#include <linux/module.h>
#include <linux/init.h>
#include <linux/cdev.h>
#include <linux/fs.h>
#include <linux/uaccess.h>
#include <linux/device.h>
#include <linux/gpio.h>

#define DRIVER_NAME "zidandriver"
dev_t mydevice_id;

static char led1[3] = {0};
static char led2[3] = {0};
#define DEVICE_SIZE 1024
char device[DEVICE_SIZE];

enum devv
{
    LED1 = 2,
    LED2 = 3
} Status;

struct class *iti_class;

struct cdev device_driver1;

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Zidan");
MODULE_DESCRIPTION("A Simple Kernel Module");

//////////////////////////////////file operations/////////////////////////////////

int driver_open(struct inode *device_file, struct file *instance)
{
    printk("Open Was called\n");
    int minor = MINOR(device_file->i_rdev);
    int major = MAJOR(device_file->i_rdev);
    instance->private_data = &minor;
    return 0;
}

int driver_close(struct inode *device_file, struct file *instance)
{
    printk("Open Was closed\n");
    return 0;
}

ssize_t driver_read(struct file *file, char __user *userr, size_t count, loff_t *)
{
    // return 0 to stop the read because the count dont stop
    return 0;
}

ssize_t driver_write(struct file *file, const char __user *userr, size_t count, loff_t *offs)
{
    printk("the count is %ld , and the offset %lld \n", count, *offs);
    int to_copy, notcopied, copied;
    int space_available = DEVICE_SIZE - *offs;
    if (space_available == 0)
    {
        return count;
    }
    // if space avaiable not enough to push count , so i will get the minimum and just copy the available
    to_copy = min(count, (size_t)space_available);
    notcopied = copy_from_user(device + *offs, userr, to_copy);
    copied = to_copy - notcopied;
    *offs += copied;

    return copied;
}

/////////////////////////////////////////////////////////////////////////////////

static struct file_operations file_op = {
    .owner = THIS_MODULE,
    .open = driver_open,
    .release = driver_close,
    .read = driver_read,
    .write = driver_write,

};

static int __init lkm_init(void)
{
    if (alloc_chrdev_region(&mydevice_id, 0, 1, DRIVER_NAME) < 0)
    {
        printk(KERN_ALERT "Failed to allocate device number\n");
    }
    else
    {
        printk("Device Major %d\n , Minor %d\n", MAJOR(mydevice_id), MINOR(mydevice_id));
    }

    if (NULL == (iti_class = class_create("iti_class_2")))
    {
        printk("CLASS CAN NOT BE CREATED\n");
    }
    else
    {
    }

    if (cdev_add(&device_driver1, mydevice_id, 1) == -1)
    {
        printk("cdev add failed\n");
    }

    cdev_init(&device_driver1, &file_op);
    // DEVICES

    // LED1-> Device 1

    // LED2 -> Device 2

    if (gpio_request(2, "FOR LED1"))
    {
        printk("cannot allocate gpio 2\n");
    }
    else
    {
        printk("Gpio pin 2 allocated successfuly\n");
    }

    if (gpio_direction_output(2, 0))
    {
        printk("cannot set gpio 2 direction as output\n");
        gpio_free(2);
    }
    else
    {
        printk("gpio 2 allocate successfully\n");
    }

    //////////////////3////////////////////

    if (gpio_request(3, "FOR LED2"))
    {
        printk("cannot allocate gpio 3\n");
    }
    else
    {
        printk("Gpio pin 3 allocated successfuly\n");
    }
    if (gpio_direction_output(3, 0))
    {
        printk("cannot set gpio 3 direction as output\n");
        gpio_free(3);
    }
    else
    {
        printk("gpio 3 allocate successfully\n");
    }

    char *dev_names[2] = {
        [0] = "LED1",
        [1] = "LED2"};

    for (int i = 0; i < 2; i++)
    {

        if (NULL == device_create(iti_class, NULL, mydevice_id + i, NULL, dev_names[i]))
        {
            printk("Device can not be created");
        }
    }

    return 0;
}
static void __exit lkm_exit(void)
{

    for (int i = 0; i < 2; i++)
    {
        device_destroy(iti_class, mydevice_id + i);
    }
    gpio_free(2);
    gpio_free(3);

    class_destroy(iti_class);
    unregister_chrdev_region(&mydevice_id, 1);

    printk("Hello Exit\n");
}

module_init(lkm_init);

module_exit(lkm_exit);

-----------------------------------------------------------------------------------------------
#include <linux/module.h>
#include <linux/init.h>
#include <linux/cdev.h>
#include <linux/fs.h>
#include <linux/uaccess.h>
#include <linux/device.h>
#include <linux/gpio.h>

#define DRIVER_NAME "zidandriver"
dev_t mydevice_id;

static char led1[3] = {0};
static char led2[3] = {0};
#define DEVICE_SIZE 1024
char device[DEVICE_SIZE];

enum devv
{
    LED1 = 2,
    LED2 = 3
} Status;

struct class *iti_class;

struct cdev device_driver1;

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Zidan");
MODULE_DESCRIPTION("A Simple Kernel Module");

//////////////////////////////////file operations/////////////////////////////////

int driver_open(struct inode *device_file, struct file *instance)
{
    printk("Open Was called\n");
    int minor = MINOR(device_file->i_rdev);
    int major = MAJOR(device_file->i_rdev);
    instance->private_data = &minor;
    return 0;
}

int driver_close(struct inode *device_file, struct file *instance)
{
    printk("Open Was closed\n");
    return 0;
}

ssize_t driver_read(struct file *file, char __user *userr, size_t count, loff_t *)
{
    // return 0 to stop the read because the count dont stop
    return 0;
}

ssize_t driver_write(struct file *file, const char __user *userr, size_t count, loff_t *offs)
{
    printk("the count is %ld , and the offset %lld \n", count, *offs);
    int to_copy, notcopied, copied;
    int space_available = DEVICE_SIZE - *offs;
    if (space_available == 0)
    {
        return count;
    }
    // if space avaiable not enough to push count , so i will get the minimum and just copy the available
    to_copy = min(count, (size_t)space_available);
    notcopied = copy_from_user(device + *offs, userr, to_copy);
    copied = to_copy - notcopied;
    *offs += copied;

    return copied;
}

/////////////////////////////////////////////////////////////////////////////////

static struct file_operations file_op = {
    .owner = THIS_MODULE,
    .open = driver_open,
    .release = driver_close,
    .read = driver_read,
    .write = driver_write,

};

static int __init lkm_init(void)
{
    if (alloc_chrdev_region(&mydevice_id, 0, 1, DRIVER_NAME) < 0)
    {
        printk(KERN_ALERT "Failed to allocate device number\n");
    }
    else
    {
        printk("Device Major %d\n , Minor %d\n", MAJOR(mydevice_id), MINOR(mydevice_id));
    }

    if (NULL == (iti_class = class_create("iti_class_2")))
    {
        printk("CLASS CAN NOT BE CREATED\n");
    }
    else
    {
        if (NULL == device_create(iti_class, NULL, mydevice_id, NULL, "iti"))
        {
            printk("Device can not be created");
        }
    }

    if (cdev_add(&device_driver1, mydevice_id, 1) == -1)
    {
        printk("cdev add failed\n");
    }

    cdev_init(&device_driver1, &file_op);

    //////////////////3////////////////////

    return 0;
}
static void __exit lkm_exit(void)
{

    device_destroy(iti_class, mydevice_id);

    class_destroy(iti_class);
    unregister_chrdev_region(&mydevice_id, 1);

    printk("Hello Exit\n");
}

module_init(lkm_init);

module_exit(lkm_exit);
-------------------------------------------------------------------------------------------------------------------

platform bus or virtual bus

i have device tree 

i have to mention that led connected to gpio pin 1  ,2 connected to gpio

   
i register led 1 and register driver one on the virtual bus through platform subsystem

driver 1 search for  what nodes are related to it and call prob=prob-func


and then mount it under /dev 






In the context of device drivers and virtual buses, the term "prob" might refer to the process of "probing" devices. Probing is an essential part of the device driver initialization process and is related to how the kernel detects and initializes hardware devices. Here's a brief overview:

Probing in Device Drivers
Device Probing:

Definition: Device probing is the process where the kernel identifies devices on the system and attempts to initialize them. It involves detecting hardware and determining if there are drivers available that can manage the device.
Purpose: Probing helps the operating system understand which devices are present, their capabilities, and how to interact with them.
Virtual Bus:

Definition: A virtual bus is a software construct that emulates the behavior of a hardware bus. It allows for the connection and communication of virtual devices within a system.
Usage: Virtual buses are used in various scenarios, including virtualized environments, system emulators, and when developing virtual devices or drivers for testing.
Probing Process:

Initialization: During initialization, the kernel will probe for devices by looking at the device tree or system buses.
Device Matching: Drivers are matched to devices based on identifiers and capabilities. Probing helps in this matching process.
Driver Binding: If a suitable driver is found, the driver binds to the device and initializes it.
Example in Linux Kernel
In the Linux kernel, probing might involve functions like probe() in device driver code. Here’s a simplified example:

c
Copy code
static int my_device_probe(struct platform_device *pdev)
{
    // Initialization code for the device
    return 0;
}

static struct platform_driver my_device_driver = {
    .probe = my_device_probe,
    .driver = {
        .name = "my_device",
        .owner = THIS_MODULE,
    },
};

module_platform_driver(my_device_driver);
In this example:

my_device_probe is a function that is called when the device is detected.
module_platform_driver registers the driver with the kernel.
Summary
In the context of device drivers and virtual buses:

Probing refers to the process of detecting and initializing devices.
A virtual bus is a software representation of a hardware bus, used for virtual devices.
The probing process involves detecting devices and matching them with available drivers.
If you have a specific context or code related to prob, please provide more details for a more tailored explanation.
