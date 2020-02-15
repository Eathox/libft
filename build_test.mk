# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    build_test.mk                                      :+:    :+:             #
#                                                      +:+                     #
#    By: Noah Loomans                                 +#+                      #
#                                                    +#+                       #
#    Created: Invalid date        by                #+#    #+#                 #
#    Updated: 0003/01/01 00:00:00 by               ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

$(OUTDIR)/cache/test/$(module)/%_test.o: $(module)/%_test.c \
		$(all-public-headers) $($(module)-private-headers)
	@mkdir -p $(dir $@)
	@$(call FNC_PRINT_PLUS,$(notdir $(NAME)),$(notdir $@))
	@$(CC) -c $(CFLAGS) $(INCLUDE) $(shell pkg-config --cflags criterion) -o $@ $<
