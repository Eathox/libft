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

function linuxInstall {
	sudo add-apt-repository -y ppa:snaipewastaken/ppa
	sudo apt-get update
	sudo apt-get install -y criterion-dev
	sudo apt-get install pkg-config
}

function osxInstall {
	export HOMEBREW_NO_AUTO_UPDATE=1

	brew install snaipe/soft/criterion
	brew install pkg-config
}

function generalInstall {
	git clone https://github.com/thijsdejong/codam-norminette-plus ~/norminette+
}

if [ -z "$GITHUB_ACTION" ]; then
	echo "Error: Not running github actions"
	exit 1
fi

OS_NAME=$(uname -s)
if [[ $OS_NAME == "Linux" ]]; then
	linuxInstall
	generalInstall
elif [[ $OS_NAME == "Darwin" ]]; then
	osxInstall
	generalInstall
else
	echo "Error: OS is not supported"
	exit 1
fi
