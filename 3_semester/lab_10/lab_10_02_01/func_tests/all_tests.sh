#!/bin/bash

> out.tmp

echo "POSITIVE TESTS"
bash ./make_pos_func.sh
echo "NEGATIVE TESTS"
bash ./make_neg_func.sh

find . -name "*.tmp" -delete
