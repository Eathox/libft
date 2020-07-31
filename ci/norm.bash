#!/usr/bin/env bash
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

NORM_DIR="norm"
NORMPLUS_DIR="$HOME/norminette+/run.py"

ERROR=false

function authorFile {
	if [ ! -f $NORM_DIR/author ]; then
		echo "Error: no author file present"
		ERROR=true
	fi
}

function normPlus {
	FILES=$(find $NORM_DIR -type f)
	NORM=$(python "$NORMPLUS_DIR" $FILES | grep -v 'Warning: Not a valid file')
	NORM=$(echo "$NORM" | grep -B1 --color=never -E '(Error|Warning:)')

	if [[ "$NORM" != "" ]]; then
		echo "$NORM"
		ERROR=true
	else
		echo "Zero normPlus errors found."
	fi
}

authorFile
normPlus

if [ "$ERROR" != false ]; then
	exit 1
fi
