#!/bin/bash
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

OS_NAME=$(uname -s)

function general {
	make test GCOV=TRUE
}

if [ -z "$GITHUB_ACTION" ]; then
	echo "Error: Not running CI"
	exit 1
fi

if [[ $OS_NAME == "Linux" ]]; then
	general
elif [[ $OS_NAME == "Darwin" ]]; then
	general
else
	echo "Error: OS is not supported"
	exit 1
fi
