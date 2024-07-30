## HISTORY OF YOCTO

Started by  **open embedded community** 


they build a tool based on python called **bitbake**

CONF ->bitbake->image

they called CONFIGURATION **metadata**








## HOW TO GET THE TOOL ?
from openembedded github

##HOW ?

```sh
mkdir image_generate_dir


## bit bake tool created by open embbedded community
git clone bitbake 


```

## then they create layers 

those layers contain application 

## what if i need python on my image

1. seach for the layer contain these application 

2. for example it is meta-core 

3. go and get clone for meta-core 

```sh
mkdir meta-core

git clone meta-core
```

## but what if i want to download the packages that support my board (kernel,uboot,cross,compiler)

**there is a layer has board support packgaes called meta-raspberrypi

```sh 

mkdir meta-rpi

git clone meta-raspberrypi

```
## so Meta refere to layer 

## what is the layer types ?

1. application (UserSpace)
 
2. Board support package (HW Space)

3. at some times we merge two into one layer 

## here there is a problem i don't know what iam doing or how these folder gonna interact with bitbake


## here YOCTO appears 

what is yocto ?

- it is a community also it is a reference teach us how to build your own distribution using openembedded 

**yocto started by creating their own layers**

1. meta-poky (contain applications)

2. meta-yocto-bsp (contain hardware support package) 

and then they make a repo on github contain the following 

1. both layers the create

2. add to them the most important layers on openembedded like

 
(meta-core) , 

(meta) ,

(meta-skeleton)  -> it is a templete for how to create board support packages

3. bitbake build engine

**and they called it Poky**
  
## So What is Poky ?  
Poky is the reference distribution of the Yocto Project, providing a set of tools and metadata to create custom Linux distributions for embedded systems. It includes everything needed to get started with the Yocto Project, including a build system, default configurations, and example recipes. 

## What is bitbake

BitBake is the build engine used by the Yocto Project and other similar projects. It parses recipes, handles dependencies, and orchestrates the build process, allowing developers to automate the compilation and assembly of software components and it was developed by openembedded.


![png](images/1.png)


## Also YOCTO community has provide comptability between bitbake buildengine version and meta-layers 

how ? 

before yocto if some one clone the following 

1. bitbake (v20)
2. meta-core (v.10) 

it generate a problem for sure 

## HOW YOCTO MADE IT COMPTABLE ?

they did poky branches (releases) 

ex: 
zeus: Yocto Project 3.0 release. 

so all the contributers that write a meta-layer , they create it depend on comptability with the branch (zeus) 
so if i want to clone meta-layer i will clone it to comptable with my branch 

every poky branch it is LTS (LONG TERM SUPPORT UNTILL A SPECIFIC DATA )

## Most famous poky branches 

1. zeus: Yocto Project 3.0 release.

2. dunfell: Yocto Project 3.1 LTS release.

3. gatesgarth: Yocto Project 3.2 release.

4. hardknott: Yocto Project 3.3 release.

5. honister: Yocto Project 3.4 release.

6. kirkstone: Yocto Project 4.0 LTS release.

7. langdale: Yocto Project 4.1 release. 

## how to clone a layer ? 

1. git clone poky with a krinkstone 

2. git clone specific layer 

3. git checkout krikstone

**if there is a confliction bitbake will notify**

## bitbake

![layer](images/layer.png)


## application layer 

![layer](images/APPLAYER.png)

## bsp layer

![layer](images/BSPLAYER.png)


## BAKE PROCESS DONE BY BIT-BAKE 

- bitbake -> bake a recipe by passing to him the receipe (instruction ,configurations) 

![layer](images/bakingprocess.png)



- receipe is written by me and i should follow this structure 

![layer](images/LayerStucture.png)


