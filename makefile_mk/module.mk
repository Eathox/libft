# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    module.mk                                          :+:    :+:             #
#                                                      +:+                     #
#    By: pholster <pholster@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/02/15 18:10:33 by pholster      #+#    #+#                  #
#    Updated: 2020/02/15 18:10:33 by pholster      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

INCLUDE_PATH := $(OUTDIR)/include/ft
REG_CACHE_PATH := $(OUTDIR)/cache/reg
TEST_CACHE_PATH := $(OUTDIR)/cache/test

# Include header dependencies for all compiled files
DEPENDENCIES := $(patsubst %.o,%.d, $($(module)-objects) $($(module)-tests))
EXISTING-DEPENDENCIES := $(wildcard $(DEPENDENCIES))
ifneq ($(EXISTING-DEPENDENCIES),)
include $(EXISTING-DEPENDENCIES)
endif

# Rule used to copy module header
$(INCLUDE_PATH)/%.h: $(SRCDIR)/$(module)/%.h
	@mkdir -p $(dir $@)
	@cp $< $@

# Rule used for regular objects
$(REG_CACHE_PATH)/$(module)/%.o: $(SRCDIR)/$(module)/%.c
	@mkdir -p $(dir $@)
	@$(call FNC_PRINT_PLUS,$(BASENAME),$(subst $(REG_CACHE_PATH)/,,$@))
	@$(CC) -c $(CFLAGS) $(INCLUDE) -o $@ $<

# Rule used for test objects
$(TEST_CACHE_PATH)/$(module)/%.o: $(SRCDIR)/$(module)/%.c
	@mkdir -p $(dir $@)
	@$(call FNC_PRINT_MISC,$(BASENAME),$(subst $(TEST_CACHE_PATH)/,,$@))
	@$(CC) -c $(CFLAGS) $(INCLUDE) -o $@ $< \
		$(shell pkg-config --cflags criterion)
