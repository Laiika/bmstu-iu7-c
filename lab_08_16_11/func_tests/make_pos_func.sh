#!/bin/bash

for out_file in pos*_out.txt
do
    args_file=$(basename $out_file _out.txt)"_args.txt"
    args=$(head -1 $args_file)

    echo ""
    echo "Command line parameters: "$args
    ../$args
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
