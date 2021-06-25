#!/usr/bin/env bash

OS_NAME=$(uname -s)

function linux {
	sudo add-apt-repository -y ppa:snaipewastaken/ppa
	sudo apt-get update
	sudo apt-get install -y criterion-dev
	sudo apt-get install pkg-config
}

function osx {
	export HOMEBREW_NO_AUTO_UPDATE=1

	brew install snaipe/soft/criterion
	brew install pkg-config
}

function general {
	pip install --upgrade pip setuptools
	pip install cpp-coveralls
}

if [[ $OS_NAME == "Linux" ]]; then
	linux
	general
elif [[ $OS_NAME == "Darwin" ]]; then
	osx
	general
else
	echo "Error: OS is not supported"
	exit 1
fi
