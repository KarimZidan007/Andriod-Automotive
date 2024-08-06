# INIT PROCESS

## WHAT IS INIT PROCESS ?

![out](images/whatisinit.png)
![out](images/whatisinit1.png)
![out](images/whatisinit2.png)

```sh
# it display the process with it's PID
pstree -p
```


## WHAT IS THE TYPES OF INIT PROCESS ?

![out](images/type.png)

## WHAT IS THE DIFFERENCE BETWEEN THEM

![out](images/diff.png)


## 1-Busybox

![out](images/busybox1.png)
![out](images/busybox2.png)
![out](images/busybox3.png)

- you could go back and see how we customized simple busybox init process from here:

(https://github.com/KarimZidan007/Andriod-Automotive/tree/main/Embedded_Linux_NOTES/4-FS-BusyBox)

## 2-SystemV

**the busybox init process is just a trimmed version of SystemV**

![out](images/SysV1.png)


**runlevels is equal to mode**

## Common Runlevels and Targets

1. `S:Runs startup tasks`

2. `0: Halt (shutdown)`

3. `1: Single-user mode`

4. `2: Multi-user mode without network configurations`

5. `3: Multi-user mode with network (multi-user.target)`

6. `4: Userdefined`

7. `5: Multi-user mode with GUI (graphical.target)`

8. `6: Reboot`

## what is the default run level ?

**mode is used to reduce cpu load on the system**
![out](images/default.png)

## how to know your current run level ?

```sh
runlevel
```
![out](images/runl.png)

## SWITCH TO ANOTHER RUNLEVEL

using init command or telinit

```sh
#switch to Multi-user mode with GUI 

init 5

```
## How Runlevels works ?

![out](images/runlev.png)


## Why it is Important for embedded linux ?

![out](images/1.png)

1. Application Mode/UserMode (Infotainment with all functionallity)

2. maintainance mode -> (Flash a new Software , Diagnostic on service center)




## inittab

![out](images/inittab.png)
![out](images/inittab2.png)
![out](images/inittab3.png)

```sh
node :runlevel : action :script
: R 1 2 3 4 5 6: wait :rc

```
### rc is the run level handling script ,it is going to be discussed in next lines 

## 1- Creating scripts under /etc/init.d

![out](images/init.d1.png)

![out](images/init.d2.png)

**NOTE**
this scripts not the binaries it self it is a scripts just call or kill the application from /bin 

![out](images/2.png)

**how to write this script. example:**

imagine creating a program named dempapp it forks and runs in background (as a daemon) and we move the binary (demoapp) on /bin we will need an init.d script such as this.

![out](images/4.png)

## 2- make runlevel directories under /etc/rc1.d , /etc/rc5.d ..etc

**1- each run level has its own folder**

**2- make softlink for required scrips**

![out](images/3.png)

###to make DemoApp opertional,copy the script to the target directory called /etc/init.d/DemoAPP and make it executable then , add links from each of the run levels you want to run this program from like this example with runlevel 5

`S -> Start `
`K -> Kill`

```sh
cd /etc/init.d/rc5.d


ln -s ../init.d/DemoAPP  S11DemoAPP

```
### the two number following the symbolic link indicate the priority of Starting



Another Example : if i want to make a mode that disable network ,and enable ssh

1. make softlink for network,ssh on the directory 


if i want to start a new script on the mode write S before it

- if i want to kill a running script on the mode write K before it

- add a number after S , K for a priority 


```sh
ln -s /etc/init.d/network Ko1network
ln -s /etc/init.d/ssh  So2ssh
```
![out](images/5.png)


- there is a command check where run level am i 


## rc script

- it could be devleoped with c ,or as a sh script


```c
switch(runlevel)
{
1:
    cd /etc/rc1.d/
    parse for all file start with k with forloop (increment with priority) on rc1.d
    for(parsing(k),0)
    {
    # this script which locate on /etc/init.d
    script(stop)
    //so this script will kill all running applications on rc1.d 
    }

etc
```
## Summary of System V Init Process

 ![out](images/Sysv.png)

- Kernel initializes and calls init.
- init reads /etc/inittab.
- init executes rcS script.
- rcS mounts filesystems and sets runlevel (e.g., init 5).
- init reads /etc/inittab for runlevel 5.
- init calls rc script to handle runlevel transition.
- rc script stops and starts services based on /etc/rcX.d/.
- System operates at runlevel 5.
- User requests runlevel 3 (e.g., init 3).
- init reads /etc/inittab for runlevel 3.
- rc script handles transition to runlevel 3 (init proc does not called rcs again because it is sysinit) . 

## Problem of System V

every thing initialized sequential not parallel even if i have multicores so booting speed is slow


## TASK


 add a new run level to system v

### here is the link of TASK STEPS
()

## 3-SystemD

it use parallisim 


## system d vs system v


![out](images/6.png)


initprocess softlink /lib/systemd/system

/lib/systemd/systemd -> normal c code 

## 2 Main directories in systemd

1. /etc/system/systemd/ -> customizable

2. /lib/systemd/system

3. /run/systemd

system d interdouce unit (file)

units under two paths 

1. /etc/system/systemd/

![out](images/7.png)

2. /lib/systemd/system

![out](images/8.png) 

3. 3. /run/systemd

## unit types

1. service 
2. mount 
3. network
4. automount 
5. socket  
and there is more



## every unit has a different concept to run


![out](images/9.png) 

## example for a unit file

![out](images/10.png) 

## how to write a unit 
under conifguration /etc/systemd/system

touch name.(typeofservice)

```sh
touch myservice.service 
```
but before intrdouce service we need to know more about process

types of process 

1- foreground 

2- background 

3- orphan process 
process its parent has been killed at this case on system d this process gonna be adapted by the first process (PID 1)

4- zombie process
if i have 1   ->    2   ->   3    -> if 3 has been finish but 2 does not get its exit status because parent maybe on while 1  
so 

1. it takes one of the process column on the process table that kernel give the system on ram
    (we can increment process table number kernel could create -> cat /proc/sys/kernel/pid_max) , also (we can increment number of file describtors )


5- daemon process
it is the same concept of background but i can not make it a foreground

so System D based on daemons -> services  to display daemons
 
```sh 

jobs
```

unitfile is has three sections

1. Header section 
EX:

```sh
[Unit]
Description=" description for my own unit file "
Documentation= "            "
SourcePath="ApplicationPath"
Before="Unit file"-> run the current service (i develop it now) before "Unit file" don't wait for my completion
After="Unit file" -> run the current service (i develop it now) after "Unit file" don't wait for completion
wants="Unit file" -> wait for this unit to run then make sure it is on active state
requires=run myservice wait till i go into active state
```
## SERVICE(CONFIG FILE)+APPLICATION = DAEMON

```sh
[Service]

Type = typeof process

1. simple -> service  -> /usr/bin/hello    (hello -> while(1)) / will run application directly

init Proc -> .Service -> hello  (if i make stop to service will die (strong coupled))
-------------------------------------------------------------------------------------------------------------
2. oneshot

like initialization (a service just run for a one time)
-------------------------------------------------------------------------------------------------------------
3. forking

init Proc -> .Service -> .hello   (if i make stop will not die until i kill it losely coupled  )

-------------------------------------------------------------------------------------------------------------
ExecStart =application to run (only one has one only Exec Start) -> Systemctl start



ExecStop =what happen when i stop service (run this application when you send stop signal to the service) systemctl stop

Workdir=/usr/bin/Service  (just to do not right full pass everytime)


restart=on-failure -> when it return exit status (fails) , always -> when application ends start it again 

Restart sec =3 -> wait 3 seconds before start one more time 

```

## STEPS 

```sh
touch myserivce.service 
touch mynetwork.network


```


```sh

my.service.service

[Unit]

wants=mynetwork.network

[Service]

Type=simple

execstart=ping 192.168.1.10 -t // rasp or qemu  

Restart=Always 
restartSec=3
WorkDir=/usr/bin

[Install]
wantedBy=graphic.target -> it is a folder that softlink to my service (myservice.service) 

# did i create soft link by myself ? 

no you just type systemctl enable service

```


```sh

myNetwork.network

[Unit]

Name="interface name"

[Network]

ip=192.168.1.9
subnet=255.255.255.0

After=mynetwork.network


```

## COMMANDS

systemctl (1. start - 2. stop - 3.cat - 4.edit) -> service 

systemctl get-default , set-default 

OUTPUT

```sh
graphical.target
```

## WHAT IS THE TARGET 
group of services which is equal runevel on system v 

collection of services 


## where iam going to create any unit 
```
/etc/systemd/system
```

2. then touch myservice.service


3. and write that it is wanted by= graphical.target which is a directory 

4. systemctl enable myservice (once i write it it will softlink to myservice.service)


## ATFIRST SYSTEMD RUNS TARGET AT FIRST 

what is that 

```sh 
systemctl get-default
```

how to change my default ? 

```sh
systctl set-default multi-user-target

```

how to disable the default ? 

```sh

systemctl disable multi-user-target
```

systemctl (units)


![x](images/11.png)
 


```sh


journal

```
## steps

1. systemctl stop tftpd-hpa.service 

2. status

3. systemctl restart myservice.service 
