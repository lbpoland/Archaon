#!/bin/bash
/mnt/home2/dawn/AI_lounge/stop_ai.sh
/mnt/home2/dawn/AI_lounge/stop_mud.sh
sleep 2
/mnt/home2/dawn/AI_lounge/start_ai.sh
/mnt/home2/dawn/AI_lounge/start_mud.sh
echo "Both AI script and MUD driver restarted"
/mnt/home2/dawn/AI_lounge/check_status.sh
