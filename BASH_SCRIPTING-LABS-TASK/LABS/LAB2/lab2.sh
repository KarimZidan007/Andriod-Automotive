#!/bin/bash

OPTIONS=("Display date and time" "List files in current directory" "Display current disk usage" "Exit")
PS3="Please Choose an option : "

select TEST in "${OPTIONS[@]}"
 do 

    case "${TEST}" in
        "Display date and time")
            echo `date`
                        
        ;;
        "List files in current directory")
            echo `ls -la`
        ;;
        "Display current disk usage")
        
            echo `df -h`
            
        ;;
        Exit)
            
               break;
    esac
done

    
