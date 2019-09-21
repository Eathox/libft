# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    get_depdancys.bash                                 :+:    :+:             #
#                                                      +:+                     #
#    By: pholster <pholster@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/09/21 03:01:50 by pholster       #+#    #+#                 #
#    Updated: 2019/09/21 03:01:50 by pholster      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

SEARCH_FILES=`ls src/$1 | grep -e ".*\.c" | sed "s/^/src\/$1\//g"`
FOUND_HEADERS=`cat $SEARCH_FILES | grep -e '#\s*include\s"' | cut -d'"' -f 2- | sed 's/.h"//g'`

echo `echo -e "$FOUND_HEADERS" | sort | uniq` | cut -c 4-