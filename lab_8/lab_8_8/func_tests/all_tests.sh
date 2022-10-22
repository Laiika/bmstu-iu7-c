#!/bin/bash

> out.tmp

echo "NEGATIVE TESTS"
bash ./make_neg_func.sh
echo "POSITIVE TESTS"
bash ./make_pos_func.sh

find . -name "*.tmp" -delete
