## SETPS 

1. sudo ip tuntap add dev tap0 mode tap (run ip a -> and you will find the new interface on down mode)

    

2. add address to tap by -> ** ip a add 192.168.1.8/24  dev tap0 

3. ip set link Tap up    -> (run ifconfig and then you will find the interface on up mode now)

or just doing it by a script

```bash
sudo ip tuntap add dev tap0 mode tap
sudo add address to tap by -> ** ip a add 192.168.1.8/24  dev tap0 
sudo ip set link Tap up  
```

then access qemu using this command 

```bash 
sudo qemu-system-arm -M vexpress-a9 -nographic -kernel u-boot -sd ~/SDCARD/EMULATEDSD.img -net nic -net tap,ifname=tap0,script=/home/karimzidantech/NETWORK_SCRIPT/qemu-ifup

```

![out](images/36.png)   

4. setenv ipaddr  (ip) 

![out](images/37.png)   
