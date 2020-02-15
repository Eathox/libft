# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    build_objects.mk                                   :+:    :+:             #
#                                                      +:+                     #
#    By: Noah Loomans                                 +#+                      #
#                                                    +#+                       #
#    Created: Invalid date        by                #+#    #+#                 #
#    Updated: 0003/01/01 00:00:00 by               ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

$(OUTDIR)/cache/reg/$(module)/%.o: $(module)/%.c \
		$(all-public-headers) $($(module)-private-headers)
	@mkdir -p $(dir $@)
	@$(call FNC_PRINT_PLUS,$(BASENAME),$(notdir $@))
	@$(CC) -c $(CFLAGS) $(INCLUDE) -o $@ $<
