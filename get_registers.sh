#!/bin/bash

SASS_FILE=$1


if [ -z $SASS_FILE ];
then

	echo "Usage:\n\n ./get_registers.sh path_to_file";
else

	cat $SASS_FILE | tail -n1 | xclip -sel clip;

	echo "Live Registers code copied to clipboard";
fi
 
