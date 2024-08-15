## platform subsystem

The platform subsystem is responsible for managing the underlying hardware and software resources. It provides a set of APIs

- **now i want to create dtsi , (every dtb file include alot ot dtsi's so i am gonna make an dtsi and include it into dts that we mkimage into dtb)**


- **Create only one file and this file include all the device on my system**

## dtsi syntax

/{ -> this called root node (contain all the devnodes)


    zidan_device1{ -> node
        compatible="ZIDAN,LED1";
        status= "okay";   
        label="redled_1";
        led_value=<1>;
        gpio_pin=<2>;
        buff_size=<3>;
        perm=<0x11>;



    };




} -> this called root node


## driver parse the the dtsi and do every thing inside it ss


1. compatible="ZIDAN,LED1";
Purpose: Specifies the compatibility of the device.
Explanation: This string tells the system or kernel that this device is compatible with the "ZIDAN,LED1" device driver or configuration. It helps the system match the device with the appropriate driver or configuration.
2. status="okay";
Purpose: Indicates the status of the device.
Explanation: The status property determines if the device is enabled or disabled. "okay" means the device is enabled and should be initialized and used by the system. "disabled" would mean the device is not used.
3. label="redled_1";
Purpose: Provides a label for the device.
Explanation: This is a human-readable name or label for the device, in this case, "redled_1". It helps identify the device in the system, especially when multiple devices of the same type are present.
4. led_value=<1>;
Purpose: Specifies the value for the LED.
Explanation: This parameter defines the value that should be assigned to the LED. The exact meaning can vary based on the system, but typically 1 might represent that the LED is turned on or set to a particular state.
5. gpio_pin=<2>;
Purpose: Defines the GPIO pin number used by the LED.
Explanation: This specifies which General Purpose Input/Output (GPIO) pin is connected to the LED. In this case, GPIO pin 2 is used.
6. buff_size=<3>;
Purpose: Specifies the buffer size.
Explanation: This parameter may define the size of a buffer used for communication or data storage related to the device. The value <3> is the size, though its exact meaning depends on the specific implementation.
7. perm=<0x11>;
Purpose: Defines permissions or attributes.
Explanation: This parameter specifies permissions or attributes related to the device, often in a hexadecimal format. The value <0x11> typically represents a set of permissions or attributes that control how the device can be accessed or used.



## after include it in dts and build it 

## there is on cf.h a struct called property 

**like a linked list every property has an instance of this struct and a member of it a struct to next properity** 

- **so here i have 7 properity like a linked list of 7 proprty** 


- **platform subsystem  takes every instance of device node and make it as an instance of struct platform_device  inside it there is struct device and return
struct platform_device**

-**struct platform_device -> has a member attribute instance of device_node point to device_node that created it**


**of (any thing related to open firmware related to dts) 


functions gonna extract the properity data from device struct that are on platform devices



------------------------

- **attributes is the setting of my device (i could control the device from it  ) like /sys/class , sys/dev** 

- could use it to change directions for gpio (change settings)

- could use it run attribute to read the value on the pin 

## how to make attribute 


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


   ## i could force yocto to take my files and make files and output modules .ko 


   -------------------------------------------------------------------------------

   there is a templete recipe that i could use it to build my files and generate .ko with files  

   this recipe called recipe-kernel copy it to my layer 


   make file will change 


there is KERNEL_SRC VAR 

search for class called module*.bbclass 

you will find 
KERNEL_SRC=STAGING_KERNEL_DIR
 

inheret modue 

S ="${WORKDIR}";


on local.conf 
to force yocto to build the module into the image
MACHINE_ESSENTIAL_EXTRA_DEPENDS +="myrecipe"


