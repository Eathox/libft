#!/bin/bash
# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    gcov.bash                                          :+:    :+:             #
#                                                      +:+                     #
#    By: pholster <pholster@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/05/24 02:44:00 by pholster      #+#    #+#                  #
#    Updated: 2020/05/24 02:44:00 by pholster      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NORM_DIR="norm"
BUILD_DIR="build"

EXCLUDE=''

cpp-coveralls -b "." --exclude "$NORM_DIR" --exclude "$BUILD_DIR/include" \
	--exclude "$BUILD_DIR/cache/test"
