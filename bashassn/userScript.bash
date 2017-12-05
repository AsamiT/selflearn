#!/bin/bash

#set -x
# for debugging

lampvar='0'
logvar='0'
ext=''
verbosevar='0'
DIRECTORY="public_html"
LOG="userlog.log"

if [ -d "$DIRECTORY" ]; then
  rm -r $DIRECTORY
fi

if [ -f "$LOG" ]; then
  rm $LOG
fi

print_cmd() {
    echo "Usage: $0"
    echo "-v : verbose mode"
    echo "-f : directory "
    echo "-d : debugging"
    echo "-l : logging enabled"
    echo "-e : extension"
    echo "-noLamp : create local HTML directories"
    exit 1;
}

create_HTML() {
  if (verbosevar=1)
  then
    echo "Creating public HTML folder..."
  fi
  mkdir 'public_html'
  touch 'public_html/index.html'
  if (verbosevar=1)
  then
    echo "Printing HTML file:"
  fi
  echo "<html>Hello world!</html>" >> 'public_html/index.html'
  cat 'public_html/index.html' #print contents to log/display
}


null() {
    echo "" >> /dev/null
}

main_func() {
  if [ $lampvar -eq 1 ]
  then
    create_HTML
  else
    echo "Skipping HTML creation..."
  fi
}

if (( $# < 1 ))
then
    print_cmd
fi

if [[ "${@#-v}" = "$@" ]]
then
    null
else
    verbosevar=1
fi

if [[ "${@#-f}" = "$@" ]]
then
  null
else
  null
fi

if [[ "${@#-l}" = "$@" ]]
then
    null
else {
  logvar=1
}
fi

if [[ "${@#-e $#}" = "$@" ]]
then
  null
else
  echo "Dicks."
fi

if [[ "${@#-noLamp}" = "$@" ]]
then
  lampvar=1
else
  null
fi

if [ $logvar -eq 1 ]
then
  main_func >> userlog.log
else
  main_func
fi

# if [[ "${@#-d}" = "$@" ]]
# then
#     null
# else {
#     set -x
#     uname -a
# }
# fi
