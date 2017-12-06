#!/bin/bash

#set -x
# for debugging

lampvar=1
logvar=0
ext='.peop'
dir='./pers'
verbosevar=0
files=0
USR='james'
DIRECTORY="/home/$USR/"
LOG="userlog.log"

print_cmd() {
    echo "Usage: $0"
    echo "-v | --verbose : verbose mode"
    echo "-f | --file : directory "
    echo "-d | --debug : debugging"
    echo "-l | --log : logging enabled"
    echo "-e | --ext : extension"
    echo "-n | --noLamp : do not create local HTML directories"
    exit 1;
}

if (( $# < 1 ))
then
    print_cmd
fi

#if [ -d "$DIRECTORY" ]; then
#  rm -r $DIRECTORY
#fi

if [ -f "files" ]; then
  rm "files"
fi

if [ -f "$LOG" ]; then
  rm $LOG
fi

while getopts "vf:dle:n" opt; do
  case ${opt} in
    v )verbosevar=1
    ;;
    f )dir=$OPTARG
    ;;
    d )neofetch
    ;;
    l )logvar=1
    ;;
    e )ext=$OPTARG
    ;;
    n )lampvar=0
    ;;
  esac
done
shift $((OPTIND -1))

create_HTML() {
  if (verbosevar=1)
  then
    echo "Creating public HTML folder..."
  fi
  mkdir '$DIRECTORY/public_html'
  touch '$DIRECTORY/public_html/index.html'
  echo "<html><b>Hello world!</b></html>" >> 'public_html/index.html'
  if (verbosevar=1)
  then
    echo "Printing HTML file:"
    cat '$DIRECTORY/public_html/index.html' #print contents to log/display
  fi
}


null() {
    echo "" >> /dev/null
}

grabNumFiles() {
  files=$(ls -1 $dir | wc -l)
}

main_func() {
    grabNumFiles
    if [ $verbosevar -eq 1 ]
    then
      echo "Number of files:" $files
      echo "Extension:" $ext
      echo "Directory:" $dir
      echo "DIRECTORY:" $DIRECTORY
    fi

    if [ $lampvar -eq 1 ]
    then
	create_HTML
    else
	echo "Skipping HTML creation..."
    fi
}

if [ $logvar -eq 1 ]
then
  main_func >> userlog.log
else
  main_func
fi
