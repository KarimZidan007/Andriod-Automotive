## Overview

This kernel module is designed to manage two LED devices via a platform driver. It provides functionality to allocate GPIO pins, set their direction, and control the LEDs based on user input. The module creates a character device that allows user-space applications to interact with the LEDs.

## Features

Platform Driver: Handles two LED devices (LED1 and LED2) using platform device bindings.
GPIO Control: Allocates and manages GPIO pins for the LEDs.
Character Device: Implements basic file operations (open, read, write, release) to control LEDs from user space.

## Module Component

**1.Device Initialization and Registration**:

1. GPIO Allocation: Allocates GPIO pins 2 and 3 for LED1 and LED2, respectively.

2. Device Creation: Creates character device nodes for each LED.

**2.File Operations**:

1. Open: Initializes the device when it is opened.

2. Close: Handles cleanup when the device is closed.

3. Read: Placeholder function, currently does nothing.

4. Write: Controls the LED state based on user input (0 to turn off, 1 to turn on).

**3.Cleanup**:

1. GPIO Deallocation: Frees GPIO pins when the module is unloaded.

2. Device Removal: Destroys device nodes and unregisters the character device.


## Building the Module

1. Ensure Kernel Headers are Installed:
```sh
sudo apt-get install linux-headers-$(uname -r)


```

2. Build the Module:Navigate to the directory containing your Makefile and run:

```sh
make
```

3. Loading the Module

```sh 
#insert the driver first
sudo insmod mydriver.ko 
## insert the two devices
sudo insmod platform_device1.ko

sudo insmod platform_device2.ko

```

4. check kernel logs
```sh

dmesg | tail
```
5. also verify that devices has created

```sh
ls /dev | grep LED
```

## use it with board has gpio interface

1.Write to the Device:
```sh
echo 1 > /dev/LED1  # Turn on LED1
echo 0 > /dev/LED2  # Turn off LED2

```

## Unloading the Module

```sh

sudo rmmod platform_device2
sudo rmmod platform_device2
# driver here gonna handle device destoring through device_remove (function)

```
1. check kernel logs
```sh

dmesg | tail
```
2. also verify that devices has been destroyed

```sh
ls /dev | grep LED
```
