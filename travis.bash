#!/bin/bash

if [ -z "$TRAVIS" ] || [ $TRAVIS != true ]; then
	echo "Error: Not running travis"
elif [ $TRAVIS_OS_NAME == "linux" ]; then
	add-apt-repository ppa:snaipewastaken/ppa
	apt-get update
	apt-get install criterion-dev
	make test
elif [ $TRAVIS_OS_NAME == "osx" ]; then
	export HOMEBREW_NO_AUTO_UPDATE=1
	brew install snaipe/soft/criterion
	make test
else
	echo "Error: OS is not supported"
fi
