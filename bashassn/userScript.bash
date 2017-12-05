#!/bin/bash

#set -x
# for debugging

if (( $# < 1 ))
then
    print_cmd
fi

print_cmd() {
    echo "Usage: $0"
    echo "-v : verbose mode"
    echo "-d : debugging"
    echo "-l : logging enabled"
    exit 1;
}

main_function() {
  echo "I can't get no... satisfaction..."
}

null() {
    echo "" >> /dev/null
}

if [[ "${@#-d}" = "$@" ]]
then
    null
else
    set -x
    uname -a
fi

if [[ "${@#-v}" = "$@" ]]
then
    null
else
    echo "Found verbose!"
fi

if [[ "${@#-l}" = "$@" ]]
then
    null
else {
    rm -f "userlog.log"
    main_function >> ./userlog.log
}
fi
