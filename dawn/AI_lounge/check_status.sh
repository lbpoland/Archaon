#!/bin/bash
echo "Checking status..."
STORED_AI_PID=$(cat /mnt/home2/dawn/AI_lounge/ai.pid 2>/dev/null || echo "")
AI_PID=$(ps -aux | grep -E '[p]ython3.*master_ai_handler\.py' | awk '{print $2}')
MUD_PID=$(ps -aux | grep -E '[d]river.*mud\.config' | awk '{print $2}')

if [ -n "$AI_PID" ] && [ "$AI_PID" = "$STORED_AI_PID" ]; then
    echo "AI script running with PID $AI_PID (matches stored PID)"
elif [ -n "$AI_PID" ]; then
    echo "AI script running with PID $AI_PID (stored PID $STORED_AI_PID mismatch)"
else
    echo "AI script not running (stored PID was $STORED_AI_PID)"
fi

if [ -n "$MUD_PID" ]; then
    echo "MUD driver running with PID $MUD_PID"
else
    echo "MUD driver not running"
fi
