#!/bin/bash
clear #clears screen

if [ ! -d $1 ]; then #makes directory if no directory of that name exists
	mkdir $1
fi

DIR_NAME=$1
cd $DIR_NAME #changes into directory

if [ ! -f "extractor.log" ]; then #makes extractor.log file if DNE
	touch extractor.log
fi

if [ ! -f "Information" ]; then #makes Information file if DNE
	touch Information
	echo "Information file is created" > extractor.log #if Information file DNE earlier, send "Information file created" to extractor.log
else
	echo "Information file already existed" > extractor.log #if file already existed, send "information file already existed" to extractor.log
fi

chmod u+rw Information #gives user read+write
chmod g+r Information #gives group read
chmod o= Information #no rights for others

echo "Access right changed for Information file" >> extractor.log 

who -q | grep -oh "\w*[abcd]\w*" > Information

echo "List of user names has been added to the Information file" >> extractor.log 

NUM_USERS=`wc -l < Information`
echo "The number of found users is: $NUM_USERS" >> extractor.log

echo "Execution of InformationExtractor script has ended successfully!"
