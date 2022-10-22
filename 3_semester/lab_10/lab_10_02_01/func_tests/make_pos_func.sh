#!/bin/bash

for in_file in pos*_in.txt
do
    echo "Test "$in_file
    cat $in_file
    echo ""
    echo "Test result:"
    cat $in_file | ../app.exe > out.tmp
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
