

## adding service with init.rc , adding a SELINUX POLICY


## on our example we are going to create a service which gonna invoke HAL .cpp file which toggle a led on GPIO 17


## so we need the following 
1- led moudle (.cpp , Android.bp) -> control toggling led for 10 times  


2- service (ledservice.cpp , Android.bp , init.led.rc ) -> service with blocking code waiting for ledservice.start to be with value (1) to invoke the led executable 


3- ADD SELINUX POLICY to allow service to invoke the led executable 

- with out you will get SELINUX PERMISSION DENIAL (YOU COULD DEBUG THROUGH dmesg)




## led module 

1- Android.bp
```bash
cc_binary {
    name: "led",
    srcs: ["src/main.cpp"],
    shared_libs: ["liblog"],
    stl: "libc++",
    cflags: ["-std=c++17"],
    installable: true,  

}

```

2- main.cpp

```cpp
#include <iostream>
#include <fstream>
#include <unistd.h>

#define GPIO_PIN 17
#define GPIO_PATH "/sys/class/gpio/"

void export_gpio(int pin) {
    std::ofstream export_file(GPIO_PATH "export");
    if (export_file.is_open()) {
        export_file << pin;
        export_file.close();
    } else {
        std::cerr << "Failed to export GPIO " << pin << std::endl;
    }
}

void set_gpio_direction(int pin, const std::string& direction) {
    std::ofstream direction_file(GPIO_PATH "gpio" + std::to_string(pin) + "/direction");
    if (direction_file.is_open()) {
        direction_file << direction;
        direction_file.close();
    } else {
        std::cerr << "Failed to set direction for GPIO " << pin << std::endl;
    }
}

void toggle_gpio(int pin) {
    std::ofstream value_file(GPIO_PATH "gpio" + std::to_string(pin) + "/value");
    if (value_file.is_open()) {
        // Toggle the value (this example toggles between 0 and 1)
        static bool pin_state = false;
        value_file << (pin_state ? "0" : "1");
        value_file.close();
        pin_state = !pin_state;
    } else {
        std::cerr << "Failed to write value to GPIO " << pin << std::endl;
    }
}

int main() {
    // Export the GPIO pin if not already exported
    export_gpio(GPIO_PIN);

    // Set the pin direction to output
    set_gpio_direction(GPIO_PIN, "out");

    // Toggle the GPIO pin in a loop
    for (int i = 0; i < 10; ++i) {
        toggle_gpio(GPIO_PIN);
        std::cout << "Toggled GPIO " << GPIO_PIN << " (iteration " << i + 1 << ")" << std::endl;
        sleep(1);  // Sleep for 1 second between toggles
    }

    return 0;
}


```



## service 
1- Android.bp
```bash
cc_binary {
    name: "ledservice",
    srcs: ["ledservice.cpp"],  
    shared_libs: ["liblog"],    
    stl: "libc++",
    cflags: ["-std=c++17"],
    installable: true,
    init_rc: ["init.led.rc"],

}

```
2- init.led.rc

```bash

service ledservice /vendor/bin/ledservice
    class late_start
    user root
    group root
    seclabel u:object_r:ledservice_exec:s0  
    on property:ledservice.start=1
        start ledservice
    on property:ledservice.start=0
        stop ledservice


```

3- ledservice.cpp

```cpp

#include <iostream>
#include <unistd.h>
#include <sys/system_properties.h>
#include <cstdlib>

bool isLedServiceStarted() {
    char value[PROP_VALUE_MAX];
    int ret = __system_property_get("ledservice.start", value);

    if (ret > 0) {

        if (std::string(value) == "1") {
            return true;
        }
    }
    return false;
}

// Function to call the led module
void callLedModule() {
    std::cout << "Starting LED service..." << std::endl;
    // Replace with the actual command to start the LED
    system("/system/bin/led");
}

int main() {

    while (true) {
        if (isLedServiceStarted()) {
            callLedModule();
        }
        sleep(1);  
    }

    return 0;
}


```

## SELINUX POLICY 

- Android os uses SELINUX , SECURITY ENHANCED LINUX , which is uses a methdology of MAC (MANDATORY ACCESS CONTROL ), so you have to allow transation from init process to ledservice process , and it require a rule added on multiple files on /system/sepolicy/private/ 

- iam going to set the label same as service name 


1- on /system/sepolicy/service_contexts 

add the follwing 
```bash

Servicename                               u:object_r:servicename_exec:s0

EX:

ledservice                                u:object_r:ledservice_exec:s0

```


2- on /system/sepolicy/ 

- create a file servicename.te

EX: 

**ledservice.te**  

add 

```bash
# Define types for ledservice
type ledservice, domain;
type ledservice_exec, exec_type, file_type;

# Type transition from init to ledservice_exec when executing ledservice
type_transition init ledservice_exec:process ledservice;

# Allow init to execute ledservice binary
allow init ledservice_exec:file { read execute };

```


3- on /system/sepolicy/file_contexts 

-add the follwing 


```bash


/PATH/TO/SERVICE-EXECUTABLE     u:object_r:SERVICENAME_exec:s0

/system/bin/ledservice          u:object_r:ledservice_exec:s0


```


**then you could compile and switch to permissive mode and everything gonna work**

**to check on which mode you are run the follwing**

```bash 

getenforce

```
- to switch to permissive mode

```bash
setenforce 0

```


## NOTE 

- if you want to move files , you have to remount your fs with rw permissions through follwing command


```bash
mount -o rw,remount / 
```
