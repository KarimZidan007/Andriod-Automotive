 #!/bin/sh


PIN_NUMB=17
IP_ADDRESS=192.168.1.15

if [[ ! -d /sys/class/gpio/gpio${PIN_NUMB} ]];then

echo ${PIN_NUMB} > /sys/class/gpio/export
sleep 1
echo "out" > /sys/class/gpio/gpio$PIN_NUMB}/direction 

fi

sleep 1

if ping -c 3 "${IP_ADDRESS}" ;then
echo 0 > /sys/class/gpio/gpio${PIN_NUMB}/value
else
echo 1 > /sys/class/gpio/gpio${PIN_NUMB}/value
fi
