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
	NORM=$(python ~/norminette+/run.py $@ | grep -v 'Warning: Not a valid file')
	NORM=$(echo "$NORM" | grep -B1 --color=never -E '(Error|Warning:)')

	if [[ "$NORM" != "" ]]; then
		echo "$NORM"
		ERROR=true
	fi
}

ERROR=0
normPlus "$(find . -not -path './src/*' -type f -name '[Mm]akefile' )"
normPlus "$(find src -type f \( -name '*.h' -o -name '*.c' \) )"

if [ "$ERROR" != 0 ]; then
	exit 1
fi

echo "Zero normPlus errors found."
