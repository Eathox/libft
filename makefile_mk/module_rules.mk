# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    module_rules.mk                                    :+:    :+:             #
#                                                      +:+                     #
#    By: pholster <pholster@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/02/15 18:10:33 by pholster      #+#    #+#                  #
#    Updated: 2020/02/15 18:10:33 by pholster      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

# Include header dependencies for all compiled files
DEPENDENCIES := $(patsubst %.o,%.d, $($(module)-objects) $($(module)-tests))
EXISTING-DEPENDENCIES := $(wildcard $(DEPENDENCIES))
ifneq ($(EXISTING-DEPENDENCIES),)
include $(EXISTING-DEPENDENCIES)
endif

# Rule used to copy module header
$(OUTDIR)/include/ft/%.h: $(SRCDIR)/$(module)/%.h
	@mkdir -p $(dir $@)
	@cp $< $@

# Rule used for regular objects
$(OUTDIR)/cache/reg/$(module)/%.o: $(SRCDIR)/$(module)/%.c
	@mkdir -p $(dir $@)
	@$(call FNC_PRINT_PLUS,$(BASENAME),$(notdir $@))
	@$(CC) -c $(CFLAGS) $(INCLUDE) -o $@ $<

# Rule used for test objects
$(OUTDIR)/cache/test/$(module)/%.o: $(SRCDIR)/$(module)/%.c
	@mkdir -p $(dir $@)
	@$(call FNC_PRINT_MISC,$(BASENAME),$(notdir $@))
	@$(CC) -c $(CFLAGS) $(INCLUDE) -o $@ $< \
		$(shell pkg-config --cflags criterion)
