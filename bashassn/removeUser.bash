if (( $# < 1 ))
then 
	echo "YOU need to specify the folder with the user files"
	exit 2;
fi

myFiles=($( ls $1 ))
for i in ${myFiles[@]}
do
	exec < $1"/"$i
	read Name
	echo "Removing "$Name
	sudo deluser $Name
	if [ $Name != "" ]; then
	sudo rm -R "/home/"$Name
	sudo rm -R "/var/www/html/"$Name"_www"
	fi
done


