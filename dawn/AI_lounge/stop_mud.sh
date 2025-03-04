#!/bin/bash
MUD_PID=$(ps -aux | grep '[d]river /mnt/home2/dawn/driver/mud.config' | awk '{print $2}')
if [ -n "$MUD_PID" ]; then
    sudo kill -TERM $MUD_PID
    echo "MUD driver (PID $MUD_PID) stopped"
else
    echo "No MUD driver running"
fi
