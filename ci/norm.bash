#!/bin/bash
# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    norm.bash                                          :+:    :+:             #
#                                                      +:+                     #
#    By: pholster <pholster@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/10/01 16:19:41 by pholster      #+#    #+#                  #
#    Updated: 2019/10/01 16:19:41 by pholster      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

function normPlus {
	NORM=$(python ~/norminette+/run.py "$1")
	NORM=$(echo "$NORM" | grep --color=never -E "(Error: [^N])" -B 1)

	if [[ $NORM != "" ]]; then
		echo "$NORM"
		exit 1
	fi
}

normPlus "$(find . -name "Makefile")"
normPlus "$(find src -name "*.c")"

echo "Zero normPlus errors found."
exit 0
