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

cpp-coveralls -b "." --exclude "build/cache/test" --exclude "build/include"
