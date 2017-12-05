#!/bin/bash

#set -x
# for debugging

if (( $# < 1 ))
then
    echo "Usage: $0"
    echo "-v : verbose mode"
    echo "-d : debugging"
    echo "-l : logging enabled"
    exit 1;
fi

main_function() {
  echo "I can't get no... satisfaction..."
}

if [ $1 = -l ]; then
    rm -f "userlog.log"
  main_function >> ./userlog.log
else
  main_function
fi

if [ $1 = -v ]; then
  main_function
  echo "Verbosity verbosity."
fi

if [ $1 = -d ]; then
    neofetch //simply execute neofetch.
fi
