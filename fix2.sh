#!/bin/bash
LIB_DIR="/mnt/home2/grok/lib"
FLUFFOS_INCLUDE="/mnt/home2/grok/fluffos/include"

fix_file() {
    local file=$1
    if [[ -f "$file" ]]; then
        echo "Processing $file"
        sed -i 's/crypt(/sha512_crypt(/g' "$file"
        sed -i 's/#include "mudos.h"/#include "config.h"/g' "$file"
        sed -i 's/int/long long/g' "$file"
        sed -i 's/query_multiple_short/sprintf("%O", /g' "$file"  # Tentative fix
        sed -i "s|\"/include/|\"$FLUFFOS_INCLUDE/|g" "$file"
        echo "Fixed $file"
    fi
}

for file in "$LIB_DIR"/{secure, std, obj, rooms}/*.c; do
    fix_file "$file"
done

echo "Recompile with: cd /path/to/fluffos && make"
