# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    run.bash                                           :+:    :+:             #
#                                                      +:+                     #
#    By: pholster <pholster@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/09/12 02:15:18 by pholster      #+#    #+#                  #
#    Updated: 2019/09/12 02:15:18 by pholster      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

function linuxRun {
	make test GCOV=TRUE
}

function osxRun {
	make test GCOV=TRUE
}

OS_NAME=`uname -s`
if [ -z "$GITHUB_ACTION" ]; then
	echo "Error: Not running travis"
	exit 1
fi

if [[ $OS_NAME == "Linux" ]]; then
	linuxRun
elif [[ $OS_NAME == "Darwin" ]]; then
	osxRun
else
	echo "Error: OS is not supported"
	exit 1
fi
