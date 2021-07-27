# Include header dependencies for all compiled files
DEPENDENCIES := $(patsubst %.o,%.d,$($(module)-objects) $($(module)-tests))
EXISTING-DEPENDENCIES := $(wildcard $(DEPENDENCIES))
ifneq ($(EXISTING-DEPENDENCIES),)
include $(EXISTING-DEPENDENCIES)
endif

# Rule used to copy over headers and correct include path's for the new location
$(HEADER_PATH)/$($(module)-parent)%.h: $(SRC_DIR)/$(module)/include/%.h
	@mkdir -p $(dir $@)
	@$(call FNC_PRINT_MISC,$(BASENAME),$(subst $(HEADER_PATH)/$($(module)-parent),,$@))
	@cp $< $@
# The header files are in the same directory as the source files. But as a
# result the include paths are relative to how the src directory is structured
# Once the header files get moved to the OUT_DIR these paths are no longer valid
# this regex replaces include statements formatted like "name/include/name.h" to "ft/name.h"
ifeq ($(OS_NAME), Linux)
	@sed -Ei 's,(\w*)\/include\/\1\.h,ft/\1\.h,g' $@
else
	$(error $(OS_NAME) regex not implemented (headers not usable))
endif

# Include flags
INC := -I$(SRC_DIR)
$(REG_CACHE_PATH)/$(module)/%.o: INC_FLAGS := $(INC) -I$(SRC_DIR)/$(module)/include
$(TEST_CACHE_PATH)/$(module)/%.o: INC_FLAGS := $(INC) -I$(SRC_DIR)/$(module)/include

# Rule used for regular objects
$(REG_CACHE_PATH)/$(module)/%.o: $(SRC_DIR)/$(module)/src/%.c $(all-headers)
	@mkdir -p $(dir $@)
	@$(call FNC_PRINT_PLUS,$(BASENAME),$(subst $(REG_CACHE_PATH)/,,$@))
	@$(CC) -c $(CFLAGS) -o $@ $< $(INC_FLAGS)

# Rule used for test objects
$(TEST_CACHE_PATH)/$(module)/%.o: $(SRC_DIR)/$(module)/src/%.c $(all-headers)
	@mkdir -p $(dir $@)
	@$(call FNC_PRINT_PLUS,$(BASENAME),$(subst $(TEST_CACHE_PATH)/,,$@))
	@$(CC) -c $(CFLAGS) -o $@ $< $(INC_FLAGS) $(shell pkg-config --cflags criterion)
