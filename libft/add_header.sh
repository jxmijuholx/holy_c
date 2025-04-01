#!/bin/bash

AUTHOR="Jami Juhola"

for file in ft_*.c; do
    # Skip if already has the header
    if grep -q "$AUTHOR" "$file"; then
        echo "Skipping $file (already has header)"
        continue
    fi

    FILENAME=$(basename "$file")
    HEADER="/** $FILENAME - $AUTHOR **/"

    # Insert header at top
    tmpfile=$(mktemp)
    echo "$HEADER" > "$tmpfile"
    cat "$file" >> "$tmpfile"
    mv "$tmpfile" "$file"

    echo "Header added to $file"
done

