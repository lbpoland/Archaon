#!/bin/bash
MUD_DIR="/mnt/home2/dawn"
AI_DIR="/mnt/home2/dawn/AI_lounge"
LOG_DIR="${MUD_DIR}/log"
SERVICE="ai.service"

case "$1" in
    start)
        echo "Starting MUD Master AI Handler..."
        if ! pgrep -f "python3 ${AI_DIR}/master_ai_handler.py" > /dev/null; then
            source ${MUD_DIR}/venv/bin/activate
            nohup ${MUD_DIR}/venv/bin/python3 ${AI_DIR}/master_ai_handler.py &> ${LOG_DIR}/master_ai_handler.out &
            echo "Master AI Handler started in background. Check logs at ${LOG_DIR}/master_ai_handler.log"
        else
            echo "Master AI Handler is already running."
        fi
        ;;
    stop)
        echo "Stopping MUD Master AI Handler..."
        pkill -f "python3 ${AI_DIR}/master_ai_handler.py"
        if [ $? -eq 0 ]; then
            echo "Master AI Handler stopped successfully."
        else
            echo "Master AI Handler was not running or failed to stop."
        fi
        ;;
    restart)
        echo "Restarting MUD Master AI Handler..."
        $0 stop
        sleep 5
        $0 start
        ;;
    status)
        echo "Checking MUD Master AI Handler status..."
        if pgrep -f "python3 ${AI_DIR}/master_ai_handler.py" > /dev/null; then
            echo "Master AI Handler is running."
        else
            echo "Master AI Handler is not running."
        fi
        ;;
    kill)
        echo "Forcibly killing MUD Master AI Handler and related processes..."
        pkill -f "python3 ${AI_DIR}/master_ai_handler.py"
        pkill -f "python3 ${MUD_DIR}/AI"  # Kill any stray AI processes
        pkill -f "${MUD_DIR}/driver/FluffOS_Driver_Setup/driver"  # Kill driver if needed
        echo "All MUD AI and driver processes killed."
        ;;
    *)
        echo "Usage: $0 {start|stop|restart|status|kill}"
        exit 1
        ;;
esac
