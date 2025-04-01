#!/bin/bash

# Colors
GREEN="\033[0;32m"
RED="\033[0;31m"
NC="\033[0m"

# Step 1: Build your library
echo -e "${GREEN}Compiling libft.a...${NC}"
make > /dev/null

# Step 2: Make sure libft.a exists
if [ ! -f libft.a ]; then
    echo -e "${RED}Error: libft.a not created. Check your Makefile or .c files.${NC}"
    exit 1
fi

# Step 3: Compile main.c with the library
echo -e "${GREEN}Compiling main.c...${NC}"
cc -Wall -Wextra -Werror main.c -L. -lft -o test

# Step 4: If compile failed, exit
if [ $? -ne 0 ]; then
    echo -e "${RED}Compilation failed. Fix errors in main.c.${NC}"
    exit 1
fi

# Step 5: Run the test
echo -e "${GREEN}Running test...${NC}"
echo "--------------------------------"
./test
echo "--------------------------------"

# Step 6: Cleanup test executable and main.o
echo -e "${GREEN}Cleaning up...${NC}"
rm -f test main.o

echo -e "${GREEN}Done.${NC}"

