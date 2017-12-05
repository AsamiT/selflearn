if (( $# < 1 ))
then
    echo "Usage: $0"
    echo "-v : verbose mode"
    echo "-d : debugging"
    echo "-l : logging enabled"
    exit 1;
fi

if [ -l $TERM]; then
  main_function 2>&1 >> /var/log/userScript_log.log
else
  main_function
fi

if [ -v $TERM ]; then
  echo "Karma Chameleon."
fi

if [ -d $TERM ]; then
    neofetch //simply execute neofetch.
fi

main_function() {
  echo "Dongs."
}