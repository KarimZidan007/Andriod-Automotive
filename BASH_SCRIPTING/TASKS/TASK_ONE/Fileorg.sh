#!/bin/bash



Source_Directory=$1

 if [[ ! -e $Source_Directory/images ]];
 then 
        mkdir $Source_Directory/images ;
 fi

 if [[ ! -e $Source_Directory/Documents ]];
 then 
    mkdir $Source_Directory/Documents ;
 fi


 if [[ ! -e $Source_Directory/others ]];
 then
    mkdir $Source_Directory/others ;
 fi


for ext in "*.jpg" "*.png" "*.gif";do

    if [ $(find $Source_Directory/$ext -maxdepth 0 -type f) ];then
    mv -v $Source_Directory/$ext $Source_Directory/images
    else
    echo "$ext :NOTFOUND"
    fi

done

for ext1 in "*.txt" "*.doc" "*.pdf";do

    if [ $(find $Source_Directory/$ext1 -maxdepth 0 -type f) ];then
        mv -v $Source_Directory/$ext1 $Source_Directory/Documents
    else
        echo "$ext1 :NOTFOUND"
    fi

done






find $1 -maxdepth 1 -type f -exec mv {} $1/others/ \;








