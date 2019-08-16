#!/bin/bash

if [ !$TRAVIS ]; then
	echo "Error: Not running travis"
elif [ $TRAVIS_OS_NAME == "Linux" ]; then
	sudo add-apt-repository ppa:snaipewastaken/ppa
	sudo apt-get update
	sudo apt-get install criterion-dev
	make -C ../ test
elif [ $TRAVIS_OS_NAME == "osx" ]; then
	export HOMEBREW_NO_AUTO_UPDATE=1
	brew install snaipe/soft/criterion
	make -C ../ test
else
	echo "Error: OS is not supported"
fi
