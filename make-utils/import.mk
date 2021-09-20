# Reset to be included variables
libraries :=
modules :=
headers :=
objects :=
tests :=

# Import the module's make.mk
include $(SRC_DIR)/$(module)/make.mk

# Set module specific variables
$(module)-parent := $(filter-out ./,$(dir $(module)))
$(module)-modules += $(patsubst %,$(module)/%, $(modules))
$(module)-headers += $(patsubst %,$(HEADER_PATH)/$($(module)-parent)%.h, $(headers))
$(module)-objects += $(patsubst %,$(REG_CACHE_PATH)/$(module)/%.o, $(objects))
$(module)-tests += $(patsubst %,$(TEST_CACHE_PATH)/$(module)/%.o, $(tests))

all-libraries += $(libraries)
all-modules += $($(module)-modules)
all-headers += $($(module)-headers)
all-objects += $($(module)-objects)
all-tests += $($(module)-tests)

# Import newly added modules
$(foreach module,$($(module)-modules),$(eval $(call MODULE_IMPORT_TEMPLATE, $(module))))
