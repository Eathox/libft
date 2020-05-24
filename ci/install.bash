#!/bin/bash
# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    install.bash                                       :+:    :+:             #
#                                                      +:+                     #
#    By: pholster <pholster@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/09/12 02:15:31 by pholster      #+#    #+#                  #
#    Updated: 2019/09/12 02:15:31 by pholster      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

OS_NAME=$(uname -s)

function linux {
	sudo add-apt-repository -y ppa:snaipewastaken/ppa
	sudo apt-get update
	sudo apt-get install -y criterion-dev
	sudo apt-get install pkg-config

	sudo apt-get install python3-setuptools
	pip3 install cpp-coveralls

	pip --version
}

function osx {
	export HOMEBREW_NO_AUTO_UPDATE=1

	brew install snaipe/soft/criterion
	brew install pkg-config

	brew install pyenv
	pyenv install 2.7.6
	pyenv global 2.7.6
	pyenv rehash
	pip3 install cpp-coveralls
	pyenv rehash
}

function general {
	git clone https://github.com/thijsdejong/codam-norminette-plus ~/norminette+
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
