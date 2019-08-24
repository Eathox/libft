#!/bin/bash

if [ -z "$TRAVIS" ] || [[ $TRAVIS != true ]]; then
	echo "Error: Not running travis"
	exit
elif [[ $TRAVIS_OS_NAME != "linux" ]] && [[ $TRAVIS_OS_NAME != "osx" ]]; then
	echo "Error: OS is not supported"
	exit
fi

make -j4 test GCOV=TRUE
