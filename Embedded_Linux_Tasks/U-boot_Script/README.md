# U-Boot Boot Script

## Overview

This U-Boot script is designed to automate the boot process by:

1. **Detecting an SD Card**: Scans multiple MMC slots to find an SD card.
2. **Loading Files from SD Card**: If an SD card is found, loads the kernel image and device tree blob from it.
3. **Fallback to Network Loading**: If no SD card is detected, attempts to load the files from a network using TFTP.
4. **Handling Absence of Options**: Prints a message if neither an SD card nor network connectivity is available.

## Script Breakdown

### 1. Initialize Environment Variables

```sh
setenv mmc_found 0
setenv mmc_target 0
```
1. mmc_found: Flag to indicate whether an MMC device (SD card) is detected.
2. mmc_target: Stores the detected MMC device number.

## 2.Detect SDCARD

```sh
for mmc_num in 0 1 2 3 4 5; do
    if mmc dev ${mmc_num}; then
        setenv mmc_found 1
        setenv mmc_target ${mmc_num}
    fi
done
```
1. Loop through MMC slots (0 to 5): Checks each slot for the presence of an SD card.

2. mmc dev ${mmc_num}: Verifies if an MMC device is present at each slot.

3. Set environment variables: Updates mmc_found and mmc_target based on the detected device.

## 3. Load Files

1. If an SD card is found:


```bash
if test ${mmc_found} -eq 1; then
    echo "SDCARD FOUND LOADING..."
    fatload mmc ${mmc_target}:1 ${kernel_addr_r} zImage
    fatload mmc ${mmc_target}:1 ${fdt_addr_r} myfile.dtp



```

- fatload mmc ${mmc_target}:1 ${kernel_addr_r} zImage: Loads the kernel image into memory.
- fatload mmc ${mmc_target}:1 ${fdt_addr_r} myfile.dtp: Loads the device tree blob into memory.


2. If no SD card is found but network connectivity is available:

```bash 
elif ping ${serverip}; then
    echo "NETWORK CONNECTION FOUND LOADING..."
    tftp ${kernel_addr_r} ${serverip}:~/SDCARD/PART1/zImage
    tftp ${fdt_addr_r} ${serverip}:~/SDCARD/PART1/myfile.dtp

```
- ping ${serverip}: Checks for network connectivity.
- tftp ${kernel_addr_r} ${serverip}:~/SDCARD/PART1/zImage: Loads the kernel image via TFTP.
- tftp ${fdt_addr_r} ${serverip}:~/SDCARD/PART1/myfile.dtp: Loads the device tree blob via TFTP.


## 4. No Options Available


```bash
else
    echo "NO OPTIONS"
```
**Environment Variables**

1. kernel_addr_r: Memory address for loading the kernel image.
2. fdt_addr_r: Memory address for loading the device tree blob.
3. serverip: IP address of the TFTP server used for network loading.


## EXPLAINATION 

1. write the script on .txt extension 

![1](/images/1.png)

2. open qemu and attach SD CARD 



```bash 
sudo qemu-system-arm -M vexpress-a9 -nographic -kernel u-boot -sd PATH/TO/EMULATEDSD.img -net nic -net tap,ifname=tap0,script=/PATH/TO/NETWORKSCRIPT

```


3. lets load the script as a .txt file like this

![1](/images/2.png)


- we load it as a .txt file just strings so we can not execute it 

![1](/images/3.png)


- if you try to execute you going to get this error

![1](/images/4.png)


**What is the solution ?**

- mkimage 

- What is mkimage?

mkimage is a tool that prepares files, such as kernel images, device tree blobs, and ramdisk images, for use with U-Boot. It generates images with headers that include metadata required by U-Boot to properly load and execute them.

```bash
sudo apt-get update
sudo apt-get install u-boot-tools
```
- simply we need it to convert our script into executable script on u-boot enviroments 

1. use this command to convert our .txt script into .img 

```bash
mkimage -A arm -T script -C none -n 'Boot script' -d /PATH/TO/SCRIPT.txt /PATH/TO/boot_script.img

```
![1](/images/5.png)

2. move it into the FAT partition of our EMULATED SDCARD


3. launch qemu 

```bash 
sudo qemu-system-arm -M vexpress-a9 -nographic -kernel u-boot -sd ~/SDCARD/EMULATEDSD.img -net nic -net tap,ifname=tap0,script=/home/karimzidantech/NETWORK_SCRIPT/qemu-ifup
```
4. load the boot_script.img into ram

```bash
fatload mmc 0:1 (address) (scriptname.img)
#then memory display at this address
md (address)
```
EX:


![1](/images/6.png)


5. now if we tried to run the script it gonna execute

![1](/images/7.png)


6. so now we gonna create simple file called zImage on the FAT Partition on SDCARD contain a string to make sure that script behave on the right way and load the kernel   

```bash 

sudo vim zImage 

```

![1](/images/8.png) 


- So now we have boot_script.img and zImage on the fat partition , we going to use boot_script.img to auto load zImage on ram as we mentioned before on the script explaination 
 
```bash
    fatload mmc ${mmc_target}:1 ${kernel_addr_r} zImage
```

7. on qemu side now we going to check on ${kernel_addr_r} the address where script has loaded zImage

**if you quit qemu you need to reload the script**

```bash
fatload mmc 0:1 (address) (scriptname.img)

```
- md (address) check that script already loaded

![1](/images/6.png)


8. now execute the script and you will find that zImage is loaded 

![1](/images/10.png) 

9. check on ${kernel_addr_r} on ram and you will find the string we wrote before on zImage "Kernel Loaded"

![1](/images/9.png)  


## now we need to make bootcmd load the script manually once autoboot called

- so we going to editenv the bootcmd (you need to enable saveenv and editenv from menuconfig first)

![1](/images/11.png) 

- once autoboot called bootcmd (firstscript of u-boot) we need the following   

1. load the script from fat partition from sd card on $kernel_addr_r which is prefered to write it directly on hex form 0x60100000 and we gonna findout why or just before loading set a new envvar to 0x60100000 and use it choose what suits u

```bash
fatload mmc 0:1 $kernel_addr_r boot_script.img 
```
2. then we need to add an offset to $kernel_addr_r because we don't need to overwrite our script so we going to edit $kernel_addr_r and save it

```bash
setenv kernel_addr_r 0x60200000 ; saveenv 
```
3. execute the script which located at 0x60100000


4. so our simple second script gonna be and save it on bootcmd 

```bash
fatload mmc 0:1 0x60100000 boot_script.img ;setenv kernel_addr_r 0x60200000 ; saveenv ; source 0x60100000
```

5. to save the script value into bootcmd (you need to enable saveenv and editenv from menuconfig first)
```bash
saveenv 
```
6. so now if you tried to 


```bash
run bootcmd
```
![1](/images/12.png) 



