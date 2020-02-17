# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    prefix.mk                                          :+:    :+:             #
#                                                      +:+                     #
#    By: pholster <pholster@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/02/15 18:10:11 by pholster       #+#    #+#                 #
#    Updated: 2020/02/15 18:10:11 by pholster      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

all-public-headers += $(public-headers)
$(module)-private-headers := $(addprefix $(module)/,$(private-headers))
all-objects += $(addprefix $(module)/,$(objects))
all-tests += $(addprefix $(module)/,$(tests))
