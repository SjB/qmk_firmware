#!/bin/sh
make -C ../../../../ ergodox-infinity-sjb
if [ $? != 0 ]; then
    exit 1
fi
echo "Flashing left hand, Press any key when ready"
read x
sudo make -C ../../../../ ergodox-infinity-sjb-dfu-util

make -C ../../../../ ergodox-infinity-sjb MASTER=right
if [ $? != 0 ]; then
    exit 1
fi
echo "Flashing right hand, Press any key when ready"
read x
sudo make -C ../../../../ ergodox-infinity-sjb-dfu-util MASTER=right
