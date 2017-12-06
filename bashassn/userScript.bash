#!/bin/bash

#set -x
# for debugging

a=1
y=0
lampvar=1
logvar=0
ext='.peop'
dir='pers'
verbosevar=0
files=0
USR='james'
DIRECTORY="/home/"
LOG="userlog.log"
userName=''
pass=''
fullName=''

print_cmd() {
    echo "Usage: $0"
    echo "-v | --verbose : verbose mode"
    echo "-f | --file : directory "
    echo "-l | --log : logging enabled"
    echo "-e | --ext : extension"
    echo "-n | --noLamp : do not create local HTML directories"
    exit 1;
}

if (( $# < 1 ))
then
    print_cmd
fi

if [ -d $DIRECTORY$USR'public_html' ]; then
    cd $DIRECTORY$USR
    rm -rf 'public_html'
fi

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
    d )set -x
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
  sudo mkdir $DIRECTORY$USR'/public_html'
  sudo touch $DIRECTORY$USR'/public_html/index.html'
  sudo chown $USR /home/$USR/public_html
  sudo chown $USR /home/$USR/public_html/*
  sudo ln -s $DIRECTORY$USR'/public_html' /var/www/html/$USR'_www'
  su -c "echo 'Hello World!' >> $DIRECTORY$USR'/public_html/index.html'" -s /bin/bash $USR
  if (verbosevar=1)
  then
    echo "Printing HTML file:"
    sudo cat $DIRECTORY$USR'/public_html/index.html' #print contents to log/display
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
    fi
    cd $dir
    while [ "$a" -le "$files" ]; do
	for i in $(cat app$a$ext); do
	    #echo $i
	    if [ $y -eq 0 ]
	    then
		userName+=$i
	    else
		null
	    fi
	    
	    if [ $y -eq 1 ]
	    then
		pass+=$i
	    else
		null
	    fi

	    if [ $y -eq 2 ]
	    then
		fullName+=$i
	    else
		null
	    fi

	    if [ $y -eq 3 ]
	    then
		fullName+=" "$i
	    else
		null
	    fi
	    y=$[$y+1]
	    
	done
	echo $userName","$fullName
	#echo $Name
	#sudo adduser --quiet --force-badname $Name
	sudo adduser --quiet --force-badname --gecos '$fullName' $userName
	USR=$userName
	if [ $lampvar -eq 1 ]
	then
	    create_HTML
	else
	    echo "Skipping HTML creation..."
	fi
	a=$[$a+1]
	y=0
	userName=''
	pass=''
	fullName=''
	wait	
    done
}

if [ $logvar -eq 1 ]
then
  main_func >> userlog.log
else
  main_func
fi
