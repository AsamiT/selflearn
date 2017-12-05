

RET=0
verbose="false"
debug="false"

if (( $# < 1 ))
then
    echo "Usage: $0"
    echo "-v / --verbose: verbose mode"
    echo "-d / --debug: debug mode"
    exit 1;
fi

while test -n "$1"; do
    case "$1" in
       	--verbose|-v)
	    verbose="true"
	    shift
	    ;;
	--debug|-d)
	    debug="true"
	    shift
	    ;;
	*)
	    echo "Usage: $0"
	    echo "-v / --verbose: verbose mode"
	    echo "-d / --debug: debug mode"
	    exit 1
	    ;;
    esac
done

if [ "$verbose" == "true" ]; then
    declare echoLog='silentEcho'
    function silentEcho() {
	:
    }    
fi

if [ "$debug" == "true" ]; then
    neofetch //simply execute neofetch.
fi

     
