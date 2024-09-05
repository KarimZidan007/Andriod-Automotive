#include <linux/module.h>
#include <linux/init.h>
#include <linux/cdev.h>
#include <linux/fs.h>
#include <linux/uaccess.h>
#include <linux/device.h>
#include <linux/gpio.h>
#include <linux/usb.h>
#include <linux/platform_device.h>
#include <linux/property.h>

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

struct cdev device_driver1; //data structure to be inserted into the device

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Zidan");
MODULE_DESCRIPTION("A Simple Kernel Module");
//---------------------------------------------------
/**
struct device_attribute myDevAttr[2]=
{
 [0]={
    .attr={
        .name="direction", //file name under class
        .mode=0666,         //permissions , S_IRUSR | S_IWUSR
    },
    .show=myDevAttrShow,  //function invoke when i make cat
    .store=myDevAttrStore, // function invoke when i wirte on it
    },
    [1]={
        .attr={
            .name="value",
            .mode=0666,
            },
            .show=myDevAttrShow,
            .store=myDevAttrStore,
            },
 };


 then implement function Create attributts under /sys/class
{

int i=0 ;
for(i=0 ; i <2 ; i++)
{
int retval =device_create_file(dev,&(myDevsAttr[i]));
if(retval)
{
printf("Failed to create sysfs attribute file ")
return retval;
}

}

}


 myDevAttrShow()
 {


 }







 */

//---------------------------------------------------
// probe fuction (called everytime a LED device is connected on platform bus )
int prob_device(struct platform_device *LED)
{
    struct device *dev = &(LED->device);
    if (device_property_present(dev, "label"))
    {
        printk("LED device is connected\n");
    }
    if (device_property_present(dev, "led_value"))
    {
    }
    if (device_property_present(dev, "gpio_pin"))
    {
    }
    if (device_property_present(dev, "buff_size"))
    {
    }
    if (device_property_present(dev, "perm"))
    {
    }

    // function extract the data from
    // dev_property_read_u32;
    // dev_property_read_string;

    // create the device under /sys/class/ and then mount it under /dev

    if (NULL == device_create(iti_class, NULL, mydevice_id + LED->id, NULL, LED->name))
    {
        printk("Device can not be created");
    }
    else
    {
        printk("Device %s created successfully\n", LED->name);
    }
    return 0;
}
// invoked when device removed from bus (unloaded rmmod )

int device_remove(struct platform_device *LED)
{
    // handle device LED1
    if (strcmp(LED->name, "LED1") == 0)
    {
        gpio_set_value(2, 0);
        gpio_free(2);
    }
    // handle device LED2
    else if (strcmp(LED->name, "LED2") == 0)
    {
        gpio_set_value(3, 0);
        gpio_free(3);
    }
    // destroy the device under /dev , /sys/class/iti_class2
    device_destroy(iti_class, mydevice_id + LED->id);
    return 0;
}

// the devices that going to be responsibled by the driver on the platform bus
struct platform_device_id device_id[2] = {
    [0] = {.name = "LED1"},
    [1] = {.name = "LED2"}};

const struct of_device_id okatDeviceIdDTS[3]{
    {.compatible = "okat,led1", .data = (void *)0},
    {.compatible = "okat,led2", .data = (void *)0},
    {}};

// data for the driver (prob function ptr , remove function ptr)
struct platform_driver platform_driver_data = {
    .probe = prob_device,
    .remove = device_remove,
    .id_table = device_id,
    .driver = {.name = "mydriver",
               .of_match_table = okatDeviceIdDTS};
}
;

//////////////////////////////////file operations/////////////////////////////////

int driver_open(struct inode *device_file, struct file *instance)
{

    int minor = MINOR(device_file->i_rdev);
    int major = MAJOR(device_file->i_rdev);
    instance->private_data = &minor;
    printk("Opened device with major number %d and minor number %d\n", major, minor);

    return 0;
}

int driver_close(struct inode *device_file, struct file *instance)
{
    printk("Open Was closed\n");
    return 0;
}

ssize_t driver_read(struct file *file, char __user *userr, size_t count, loff_t *)
{

    printk("Read Function has been Invoked\n");

    // This driver is designed for output operations only (e.g., controlling GPIO pins).
    // Read operations are not supported, so we return -ENOSYS to indicate that the
    // function is not implemented or not applicable.
    return -ENOSYS;
}

ssize_t driver_write(struct file *file, const char __user *userr, size_t count, loff_t *)
{

    printk("Write function has been Called\n");
    char(*value)[3] = NULL;
    int not_copied;
    // determine the device based  on minor number i set it based on operation happened on (driver_opened) function
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

    // This function (copy_from_user) copies data from user space memory to kernel space memory.
    // Direct access to user space from the kernel is unsafe and may lead to security vulnerabilities,
    // so we use it to safely perform this operation.
    //
    // The function handles copying `count` bytes of data from the user space buffer (`userr`)
    // to the kernel space buffer (`value`). If only part of the data can be copied due to
    // user space memory issues or other errors, `copy_from_user` will return the number of bytes
    // that could not be copied. A return value of 0 indicates success, meaning all requested data
    // was copied successfully.
    //
    // Example: If `count` is 9 bytes but only 8 bytes are successfully copied due to an error,
    // `copy_from_user` will return 1 (the number of bytes not copied). The kernel should handle
    // this situation by checking the return value and managing the error appropriately.

    not_copied = copy_from_user(value, userr, 3);
    switch (*value[0])
    {
    case '0':

        printk("led OFF");
        gpio_set_value(Status, 0);
        break;
    case '1':
        printk("led ON");
        gpio_set_value(Status, 1);
        break;
    default:
        printk("Invalid input\n");
        break;
    }
    // this function will be recursivly invoked untill succesfully writing so i want to adjust the count based on the unsuccfull data copying
    count = count - not_copied;

    return count;
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

    platform_driver_register(&platform_driver_data);

    return 0;
}
static void __exit lkm_exit(void)
{
    platform_driver_unregister(&platform_driver_data);

    class_destroy(iti_class);
    cdev_del(&device_driver1);
    unregister_chrdev_region(&mydevice_id, 1);

    printk("Hello Exit\n");
}

module_init(lkm_init);

module_exit(lkm_exit);
