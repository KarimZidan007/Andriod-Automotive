#!/bin/bash

if [[ -e ~/.bashrc ]]; then
    echo 'export HELLO=$(hostname)' >>~/.bashrc
    echo 'LOCAL=$(whoami)' >>~/.bashrc
    $(/usr/bin/xfce4-terminal.wrapper &)

fi
