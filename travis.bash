#!/bin/bash

if [ -z "$TRAVIS" ] || [ $TRAVIS != true ]; then
	echo "Error: Not running travis"
elif [ $TRAVIS_OS_NAME == "linux" ]; then
	sudo add-apt-repository -y ppa:snaipewastaken/ppa
	sudo apt-get update
	sudo apt-get install -y criterion-dev
	# make test GCOV=TRUE
elif [ $TRAVIS_OS_NAME == "osx" ]; then
	export HOMEBREW_NO_AUTO_UPDATE=1
	brew install snaipe/soft/criterion
	make test GCOV=TRUE
else
	echo "Error: OS is not supported"
fi
