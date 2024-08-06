
## Task Description

1. create an enviroment

2. create layer outside poky using skeleton

3. create recipe

4. then create on layer.conf variable that i check on the display receipe function  


5. edit on display func

6. check if (variable==3) -> display KARIM else variable ==4 display ZIDAN


## to enable display on terminal you have to add this line to your receipe

`inherit logging`
 

## STEPS

1. `source oe-init-build-env` 

2. `bitbake-layers create-layer ../meta-iti`


3. `mkdir zidan-recipes`


4. `cd zidan-recipes`


5. 

```sh
touch karim.bb`

vim karim.bb

```
![layer](images/bb.png)

4. 

```sh

cd meta-iti/conf

vim layer.conf

```
![layer](images/layer.conf.png)



5. go back to poky 

```sh

bitbake (recipe-name)

# on my case 

bitbake karim
```
## OUTPUT

![layer](images/final.png)
