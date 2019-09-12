# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    .travisScript.bash                                 :+:    :+:             #
#                                                      +:+                     #
#    By: pholster <pholster@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/09/12 02:15:18 by pholster       #+#    #+#                 #
#    Updated: 2019/09/12 02:15:18 by pholster      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

if [ -z "$TRAVIS" ] || [[ $TRAVIS != true ]]; then
	echo "Error: Not running travis"
	exit
elif [[ $TRAVIS_OS_NAME != "linux" ]] && [[ $TRAVIS_OS_NAME != "osx" ]]; then
	echo "Error: OS is not supported"
	exit
fi

make test GCOV=TRUE
