#include <linux/module.h>
#include <linux/init.h>
#include <linux/cdev.h>
#include <linux/fs.h>
#include <linux/uaccess.h>
#include <linux/device.h>
#include <linux/gpio.h>
#include <linux/usb.h>
#include <linux/platform_device.h>

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

//////////////////////////////probe///////////////////////////////
int prob_device(struct platform_device *LED)
{
    printk("%s device detected\n", LED->name);
    if (strcmp(LED->name, "LED1 ") == 0)
    {
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
    }
    else if (strcmp(LED->name, "LED2") == 0)
    {
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
    }

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
//////////////////////////////////file operations/////////////////////////////////

int device_remove(struct platform_device *LED)
{
    if (strcmp(LED->name, "LED1") == 0)
    {
        gpio_set_value(2, 0);
        gpio_free(2);
    }
    else if (strcmp(LED->name, "LED2") == 0)
    {
        gpio_set_value(3, 0);
        gpio_free(3);
    }
    device_destroy(iti_class, mydevice_id + LED->id);
    return 0;
}

//////////////////////////////////file operations/////////////////////////////////
struct platform_device_id device_id[2] = {
    [0] = {.name = "LED1"},
    [1] = {.name = "LED2"}};

struct platform_driver platform_driver_data = {
    .probe = prob_device,
    .remove = device_remove,
    .id_table = device_id,
    .driver = {.name = "mydriver"}

};

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
    printk("Read Was called\n");
    return 0;
}

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

    not_copied = copy_from_user(value, userr, 3);
    switch (*value[0])
    {
    case '0':
        gpio_set_value(Status, 0);
        printk("led OFF");
        break;
    case '1':
        gpio_set_value(Status, 1);
        printk("led ON");
        break;
    default:
        printk("Invalid input\n");
        break;
    }

    return 0;
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