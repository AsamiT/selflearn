#!/bin/bash

FILE=IrmaMoves
DATE=$(date)

if [ -f ./"$FILE" ]; then
    echo "Found old binary, deleting..."
    rm "$FILE"
fi
for VAL in "$@"
do
    echo "Compiling testcase $VAL..."
    echo "Compile time: " >> logfile
    gcc -o "$FILE" IrmaMoves.c testcases/testcase0"$VAL".c &> logfile
    echo " " >> logfile
    echo "===========" >> logfile
    echo "Compilation took place on $DATE" >> logfile
    echo "===========" >> logfile
done
