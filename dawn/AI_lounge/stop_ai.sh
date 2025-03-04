#!/bin/bash
STORED_AI_PID=$(cat /mnt/home2/dawn/AI_lounge/ai.pid 2>/dev/null || echo "")
AI_PID=$(ps -aux | grep -E '[p]ython3.*master_ai_handler\.py' | awk '{print $2}')

if [ -n "$AI_PID" ]; then
    sudo kill -TERM $AI_PID
    sleep 2
    if ps -p $AI_PID > /dev/null; then
        sudo kill -9 $AI_PID
        echo "AI script (PID $AI_PID) forcefully stopped"
    else
        echo "AI script (PID $AI_PID) stopped"
    fi
    rm -f /mnt/home2/dawn/AI_lounge/ai.pid
elif [ -n "$STORED_AI_PID" ]; then
    echo "No AI script running, but stale PID $STORED_AI_PID found; cleaning up"
    rm -f /mnt/home2/dawn/AI_lounge/ai.pid
else
    echo "No AI script running"
fi
