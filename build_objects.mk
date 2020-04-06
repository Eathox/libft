# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    build_objects.mk                                   :+:    :+:             #
#                                                      +:+                     #
#    By: pholster <pholster@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/02/15 18:10:33 by pholster      #+#    #+#                  #
#    Updated: 2020/02/15 18:10:33 by pholster      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

$(OUTDIR)/cache/reg/$(module)/%.o: $(SRCDIR)/$(module)/%.c \
		$(all-public-headers) $($(module)-private-headers)
	@mkdir -p $(dir $@)
	@$(call FNC_PRINT_PLUS,$(BASENAME),$(notdir $@))
	@$(CC) -c $(CFLAGS) $(INCLUDE) -o $@ $<
