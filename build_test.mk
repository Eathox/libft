# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    build_test.mk                                      :+:    :+:             #
#                                                      +:+                     #
#    By: pholster <pholster@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/02/15 18:10:29 by pholster      #+#    #+#                  #
#    Updated: 2020/02/15 18:10:29 by pholster      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

$(OUTDIR)/cache/test/$(module)/%_test.o: $(SRCDIR)/$(module)/%_test.c \
		$(all-public-headers) $($(module)-private-headers)
	@mkdir -p $(dir $@)
	@$(call FNC_PRINT_PLUS,$(BASENAME),$(notdir $@))
	@$(CC) -c $(CFLAGS) $(INCLUDE) $(shell pkg-config --cflags criterion) -o $@ $<
