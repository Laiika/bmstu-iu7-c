#!/bin/bash

cd "/proc/$PPID/cwd"

gcc -std=c99 -Wall -Wextra -Wpedantic -Werror -c main.c
gcc -std=c99 -Wall -Wextra -Wpedantic -Werror -c funcs.c
gcc -o main.exe funcs.o main.o

echo "Compile"

cd ./func_tests/

for in_file in neg*_in.txt
do
    echo "Test "$in_file
    cat $in_file
    echo ""
    echo "Test result:"
    cat $in_file | ../main.exe > out.tmp
    my_err=$?

    if [ $my_err -gt 0 ]
    then
        echo "NEG! " $my_err
    else
        echo "POS! " $my_err
    fi

    echo "Reality:"
    cat out.tmp
    echo ""

    out_file=$(basename $in_file _in.txt)"_out.txt"
    echo $out_file
    echo "Expectation:"
    cat $out_file
    echo ""
    cmp out.tmp $out_file > /dev/null

    if [ $? -gt 0 ]
    then
        echo "ERRRRORORORORORO!"
    else
        echo "SUUUCUCUCCUCCES!"
    fi

done

for in_file in pos*_in.txt
do
    echo "Test "$in_file
    cat $in_file
    echo ""
    echo "Test result:"
    cat $in_file | ../main.exe > out.tmp
    my_err=$?

    if [ $my_err -gt 0 ]
    then
        echo "NEG! " $my_err
    else
        echo "POS! " $my_err
    fi

    echo "Reality:"
    cat out.tmp
    echo ""

    out_file=$(basename $in_file _in.txt)"_out.txt"
    echo $out_file
    echo "Expectation:"
    cat $out_file
    echo ""
    cmp out.tmp $out_file > /dev/null

    if [ $? -gt 0 ]
    then
        echo "ERRRRORORORORORO!"
    else
        echo "SUUUCUCUCCUCCES!"
    fi

done
