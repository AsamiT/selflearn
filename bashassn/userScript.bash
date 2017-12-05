#!/bin/bash

#set -x
# for debugging

print_cmd() {
    echo "Usage: $0"
    echo "-v : verbose mode"
    echo "-d : debugging"
    echo "-l : logging enabled"
    echo "-e : extension"
    echo "-noLamp : create local HTML directories"
    exit 1;
}

main_function() {
  if [[ "${@#-noLamp}" = "$@" ]]
  then {
    mkdir 'public_html'
    touch 'public_html/index.html'
    echo "<html>Hello world!</html>" >> 'public_html/index.html'
    }
  else
    null
  fi
}

null() {
    echo "" >> /dev/null
}

if (( $# < 1 ))
then
    print_cmd
fi

if [[ "${@#-e}" = "$@" ]]
then
  null
else
  echo "Dicks."
fi

if [[ "${@#-d}" = "$@" ]]
then
    null
else {
    set -x
    uname -a
}
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
