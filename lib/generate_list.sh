#!/bin/bash

# generate_list.sh - Generates a list of all folders and files in /lib/
# Last updated: March 07, 2025

echo "Archaon MUD File/Folder List - $(date)" > /mnt/home2/grok/lib/file_list.txt
echo "----------------------------------------" >> /mnt/home2/grok/lib/file_list.txt

# Traverse /lib/ and its subdirectories
find /mnt/home2/grok/lib -type d | while read -r dir; do
    # Skip .git and other non-lib dirs if needed
    if [[ "$dir" =~ /lib/ ]]; then
        dir_name=$(basename "$dir")
        echo "Folder: $dir_name" >> /mnt/home2/grok/lib/file_list.txt
        find "$dir" -type f | while read -r file; do
            filename=$(basename "$file")
            echo "  File: $filename" >> /mnt/home2/grok/lib/file_list.txt
        done
    fi
done

echo "File list generated in /mnt/home2/grok/lib/file_list.txt"
