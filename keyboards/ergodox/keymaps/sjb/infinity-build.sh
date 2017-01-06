#!/bin/sh
make -C ../../../../ ergodox-infinity-sjb
echo "Flashing left hand, Press any key when ready"
read x
sudo make -C ../../../../ ergodox-infinity-sjb-dfu-util
make -C ../../../../ ergodox-infinity-sjb MASTER=right
echo "Flashing right hand, Press any key when ready"
read x
sudo make -C ../../../../ ergodox-infinity-sjb-dfu-util MASTER=right
