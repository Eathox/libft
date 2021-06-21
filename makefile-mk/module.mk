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

# Include header dependencies for all compiled files
DEPENDENCIES := $(patsubst %.o,%.d,$($(module)-objects) $($(module)-tests))
EXISTING-DEPENDENCIES := $(wildcard $(DEPENDENCIES))
ifneq ($(EXISTING-DEPENDENCIES),)
include $(EXISTING-DEPENDENCIES)
endif

# Rule used to copy over headers and correct include path's for the new location
$(HEADER_PATH)/%.h: $(SRCDIR)/%/$(notdir $(module)).h
	@mkdir -p $(dir $@)
	@$(call FNC_PRINT_MISC,$(BASENAME),$(subst $(HEADER_PATH)/,,$@))
# The header files are in the same directory as the source files. But as a
# result the include paths are relative to how the src directory is structured
# Once the header files get moved to the OUTDIR these paths are no longer valid
# here for this regex replaces include statements formatted like "../name/name.h" to "name.h"
ifeq ($(OS_NAME), Darwin)
	@echo "Darwin regex not implemented"
else
	@sed -E 's,\.\.\/(.*\/)?(\w*)\/\2\.h,\1\2\.h,g' $< > $@
endif

# Rule used for regular objects
$(REG_CACHE_PATH)/$(module)/%.o: $(SRCDIR)/$(module)/%.c $($(module)-headers)
	@mkdir -p $(dir $@)
	@$(call FNC_PRINT_PLUS,$(BASENAME),$(subst $(REG_CACHE_PATH)/,,$@))
	@$(CC) -c $(CFLAGS) -o $@ $<

# Rule used for test objects
$(TEST_CACHE_PATH)/$(module)/%.o: $(SRCDIR)/$(module)/%.c $($(module)-headers)
	@mkdir -p $(dir $@)
	@$(call FNC_PRINT_PLUS,$(BASENAME),$(subst $(TEST_CACHE_PATH)/,,$@))
	@$(CC) -c $(CFLAGS) -o $@ $< $(shell pkg-config --cflags criterion)
