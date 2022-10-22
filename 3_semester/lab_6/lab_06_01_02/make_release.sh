#!/bin/bash

gcc -std=c99 -Wall -Wextra -Wpedantic -Werror -c print_items_array.c
gcc -std=c99 -Wall -Wextra -Wpedantic -Werror -c print_items_with_prefix.c
gcc -std=c99 -Wall -Wextra -Wpedantic -Werror -c read_items.c
gcc -std=c99 -Wall -Wextra -Wpedantic -Werror -c sort_items_array.c
gcc -std=c99 -Wall -Wextra -Wpedantic -Werror -c main.c
gcc -o app.exe main.o print_items_array.o print_items_with_prefix.o read_items.o sort_items_array.o

echo "Compile"
