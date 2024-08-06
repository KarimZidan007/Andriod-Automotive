# You Will Find Massive Notes about System-D here (https://github.com/KarimZidan007/Andriod-Automotive/tree/main/Embedded_Linux_NOTES)


## Task Description

- Simply Create Two Services , First One Print a String on Standart Output , Second One Ping Google , but we need both are dependent , we need the second service requires the first service to run , lets figure out how 



1. `cd /etc/systemd/system`




2. Create Two units 

```sh
touch hello.service

touch myservice.service


```



3. First Unit 

`sudo vim hello.service`

```sh

[Unit]
        Description="hello"
        Before=myservice.service

[Service]
        ExecStart=/home/karim/scripts/a.out
        type=simple
[Install]
        WantedBy=multi-user.target



```
![out](images/2.png)

**Display Script that First Unit gonna execute it**
![out](images/3.png)




4. Second Service

```sh
[Unit]
        Description="this is my service" 
        After=hello.service
        Requires=hello.service
[Service]
        ExecStart=/home/karim/scripts/bash.sh
        type=simple

[Install]
        WantedBy=multi-user.target
                                   

```
![out](images/1.png)


**Ping Script that run after first service are launched**

![out](images/4.png)

5. reload 

```sh
sudo systemctl daemon-reload
```

6. lets find out the result

**1-service one is inactive**

![out](images/5.png)

**2-service two is inactive**
![out](images/6.png)

**3-once service two is started it will launch service one first**

![out](images/s1.png)

![out](images/s2.png)

