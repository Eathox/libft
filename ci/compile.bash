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

NORM_DIR="norm"
OS_NAME=$(uname -s)

function general {
	make -C $NORM_DIR OUTDIR=../build
}

if [[ $OS_NAME == "Linux" ]]; then
	general
elif [[ $OS_NAME == "Darwin" ]]; then
	general
else
	echo "Error: OS is not supported"
	exit 1
fi
