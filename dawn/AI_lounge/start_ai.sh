#!/bin/bash
source /opt/dawn_venv/bin/activate
nohup /opt/dawn_venv/bin/python3 -u /mnt/home2/dawn/AI_lounge/master_ai_handler.py > /mnt/home2/dawn/log/ai_output.log 2>&1 &
AI_PID=$!
sleep 1  # Give it a moment to start
if ps -p $AI_PID > /dev/null; then
    echo $AI_PID > /mnt/home2/dawn/AI_lounge/ai.pid
    echo "AI started with PID $AI_PID"
else
    echo "Failed to start AI"
    exit 1
fi
