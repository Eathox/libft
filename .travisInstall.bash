# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    .travisInstall.bash                                :+:    :+:             #
#                                                      +:+                     #
#    By: pholster <pholster@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/09/12 02:15:31 by pholster       #+#    #+#                 #
#    Updated: 2019/09/12 02:15:31 by pholster      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

function linuxInstall {
	sudo add-apt-repository -y ppa:snaipewastaken/ppa
	sudo apt-get update
	sudo apt-get install -y criterion-dev
}

function osxInstall {
	export HOMEBREW_NO_AUTO_UPDATE=1
	brew install snaipe/soft/criterion
}

if [ -z "$TRAVIS" ] || [[ $TRAVIS != true ]]; then
	echo "Error: Not running travis"
	exit
elif [[ $TRAVIS_OS_NAME == "linux" ]]; then
	linuxInstall
elif [[ $TRAVIS_OS_NAME == "osx" ]]; then
	osxInstall
else
	echo "Error: OS is not supported"
	exit
fi
