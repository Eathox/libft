# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    prefix.mk                                          :+:    :+:             #
#                                                      +:+                     #
#    By: pholster <pholster@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/02/15 18:10:11 by pholster      #+#    #+#                  #
#    Updated: 2020/02/15 18:10:11 by pholster      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

$(module)-private-headers := $(addprefix $(SRCDIR)/$(module)/,$(private-headers))
all-objects += $(addprefix $(module)/,$(objects))
all-tests += $(addprefix $(module)/,$(tests))
