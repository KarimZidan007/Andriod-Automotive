#include <linux/module.h>
#include <linux/init.h>
#include <linux/cdev.h>
#include <linux/fs.h>
#include <linux/uaccess.h>
#include <linux/device.h>
#include <linux/platform_device.h>

struct platform_device platDevice2 = {

    .name = "LED2",
    .id = 1, // minor number

};

static int __init device2_init(void)
{
    int ret;

    // Register the platform device
    ret = platform_device_register(&platDevice2);
    if (ret)
    {
        printk(KERN_ERR "Failed to register platform device LED2\n");
        return ret;
    }

    printk(KERN_INFO "LED2 device has been inserted\n");
    return 0;
}

static void __exit platform_device2_exit(void)
{
    platform_device_unregister(&platDevice2);
    printk("LED2 device has been removed\n");
}

module_init(device2_init);
module_exit(platform_device2_exit);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Qemu");
MODULE_DESCRIPTION("hello from iti2");