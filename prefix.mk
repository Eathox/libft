# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    libft                                              :+:    :+:             #
#                                                      +:+                     #
#    By: Noah Loomans                                 +#+                      #
#        <nloomans@student.codam.nl>                 +#+                       #
#                                                  #+#    #+#                  #
#    License: GPLv3                                ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

$(module)-private-headers := $(addprefix $(module)/,$(private-headers))
all-objects += $(addprefix $(module)/,$(objects))
all-tests += $(addprefix $(module)/,$(tests))
