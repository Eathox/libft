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

ifneq ($(wildcard $(dependency)),)
include $(dependency)
endif

$(OUTDIR)/cache/test/$(module)/%.o: $(SRCDIR)/$(module)/%.c
	@mkdir -p $(dir $@)
	@$(call FNC_PRINT_PLUS,$(BASENAME),$(notdir $@))
	@$(CC) -c $(CFLAGS) $(INCLUDE) -o $@ $< $(shell pkg-config --cflags criterion)
