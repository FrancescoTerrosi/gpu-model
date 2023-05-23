#!/bin/bash

SASS_FILE=$1


if [ -z $SASS_FILE ];
then

	echo "Usage:\n\n ./get_sass.sh path_to_file";
else

	cat $SASS_FILE | head -n1 | xclip -sel clip;

	echo "SASS code copied to clipboard";
fi
 
