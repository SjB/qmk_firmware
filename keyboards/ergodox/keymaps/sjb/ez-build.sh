#!/bin/sh

make -C ../../../../ ergodox-ez-sjb
if [ $? != 0 ]; then
    exit 1
fi

echo "Flashing, Press enter key to continue"
read x
teensy_loader_cli --mcu=atmega32u4 -w ../../../../ergodox_ez_sjb.hex
