#!/bin/bash

cities=("Cairo" "Doha" "Berlin" "Munich" "Manchester")

cities[6]="Fayoum"

echo ${cities[@]}

for city in ${cities[*]}
do
echo $city
done

echo "number of cities is ${#cities[*]}"

