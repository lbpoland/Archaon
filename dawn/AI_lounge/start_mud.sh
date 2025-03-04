#!/bin/bash
cd /mnt/home2/dawn/driver/FluffOS_Driver_Setup
sudo /mnt/home2/dawn/driver/FluffOS_Driver_Setup/driver /mnt/home2/dawn/driver/mud.config > /mnt/home2/dawn/log/driver.log 2>&1 &
echo "MUD driver started with PID $! (running as root)"
