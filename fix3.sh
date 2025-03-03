#!/bin/bash
LIB_DIR="/mnt/home2/grok/lib"
FLUFFOS_INCLUDE="/path/to/fluffos/include"

fix_file() {
    local file=$1
    if [[ -f "$file" ]]; then
        echo "Processing $file"
        sed -i 's/crypt(/sha512_crypt(/g' "$file"
        sed -i 's/#include "mudos.h"/#include "config.h"/g' "$file"
        sed -i 's/long long/int/g' "$file"  # Replace 64-bit with int for LPC compatibility
        sed -i 's/query_multiple_short/sprintf("%O", /g' "$file"  # Tentative
        sed -i "s|\"/include/|\"$FLUFFOS_INCLUDE/|g" "$file"
        echo "Fixed $file"
    fi
}

for file in "$LIB_DIR"/{secure,std,obj,rooms}/*.c; do
    fix_file "$file"
done

echo "Recompile with: cd /path/to/fluffos && make"
