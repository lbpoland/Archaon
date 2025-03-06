#!/bin/bash

# generate_checklist.sh - Generates a checklist of files in /lib/
# Last updated: March 07, 2025

echo "Archaon MUD Checklist - $(date)" > /mnt/home2/grok/lib/checklist.txt
echo "----------------------------------------" >> /mnt/home2/grok/lib/checklist.txt

find /mnt/home2/grok/lib -type d | while read -r dir; do
    if [[ "$dir" =~ /lib/ ]]; then
        dir_name=$(basename "$dir")
        echo "Folder: $dir_name" >> /mnt/home2/grok/lib/checklist.txt
        find "$dir" -type f | while read -r file; do
            filename=$(basename "$file")
            echo "  [ ] $dir_name/$filename" >> /mnt/home2/grok/lib/checklist.txt
        done
    fi
done

echo "Checklist generated in /mnt/home2/grok/lib/checklist.txt"
echo "Update [ ] to [x] manually as files are completed and git push."
