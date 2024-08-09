#include <linux/module.h>
#include <linux/init.h>
#include <linux/platform_device.h>

static struct platform_device platDevice1 = {

    .name = "LED1",
    .id = 0, // minor number

};

static int __init device1_init(void)
{
    int ret;

    // Register the platform device
    ret = platform_device_register(&platDevice1);
    if (ret)
    {
        printk(KERN_ERR "Failed to register platform device LED1\n");
        return ret;
    }

    printk(KERN_INFO "LED1 device has been inserted\n");
    return 0;
}

static void __exit device1_exit(void)
{
    // Unregister the platform device
    platform_device_unregister(&platDevice1);
    printk(KERN_INFO "LED1 device has been removed\n");
}

module_init(device1_init);
module_exit(device1_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Qemu");
MODULE_DESCRIPTION("Hello from iti");