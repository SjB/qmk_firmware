#!/bin/sh

flags=""
if [ ! -z $1 ]; then
	flags="MASTER=right"
fi

make -C ../../../../ ergodox-infinity-sjb $flags
if [ $? != 0 ]; then
    exit 1
fi
echo "Flashing left hand, Press enter key to continue"
read x
sudo make -C ../../../../ ergodox-infinity-sjb-dfu-util $flags


#make -C ../../../../ ergodox-infinity-sjb MASTER=right
#if [ $? != 0 ]; then
#    exit 1
#fi
#echo "Flashing right hand, Press enter key to continue"
#read x
#sudo make -C ../../../../ ergodox-infinity-sjb-dfu-util MASTER=right
