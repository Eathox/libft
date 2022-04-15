SRC_DIR := modules

BASENAME := libft
NAME = $(OUT_DIR)/$(BASENAME).a
TEST_NAME = $(OUT_DIR)/test-$(BASENAME)

OS_NAME := $(shell uname -s)

CFLAGS ?= -Wall -Wextra -Werror -Wpedantic -Wmissing-prototypes \
	-Wmissing-noreturn -MD

NDEBUG ?= false

# Define NDEBUG to disable assert() macro
ifeq ($(NDEBUG), true)
CFLAGS += -DNDEBUG
endif

GCOV ?= false

# Disable optimizations since they can mess up the accuracy of the GCOV reports
# "The last -O option is the one that is effective."
ifeq ($(GCOV), true)
CFLAGS += --coverage -O0
endif

include make-utils/term.mk

OUT_DIR ?= build
HEADER_PATH := $(OUT_DIR)/include/ft
REG_CACHE_PATH := $(OUT_DIR)/cache/reg
TEST_CACHE_PATH := $(OUT_DIR)/cache/test

# Include target modules
include make.mk
all-modules := $(modules)

all-libraries :=
all-headers :=
all-objects :=
all-tests :=

# Module import template, importing the makefile of the given module
define MODULE_IMPORT_TEMPLATE
include make-utils/import.mk
endef

# Import each module's makefile specifying objects and tests
$(foreach module,$(all-modules),$(eval $(call MODULE_IMPORT_TEMPLATE, $(module))))

# Remove duplicates
all-libraries := $(sort $(all-libraries))
all-modules := $(sort $(all-modules))
all-headers := $(sort $(all-headers))
all-objects := $(sort $(all-objects))
all-tests := $(sort $(all-tests))

all: $(NAME)
PHONY += all

$(NAME): $(all-headers) $(all-objects)
	@mkdir -p $(dir $@)
	@$(call FNC_PRINT_EQUAL,$(BASENAME),$@)
	@ar rcs $@ $(all-objects)

$(TEST_NAME): $(all-headers) $(all-objects) $(all-tests)
	@mkdir -p $(dir $@)
	@$(call FNC_PRINT_EQUAL,$(BASENAME),$@)
	@$(CC) $(CFLAGS) -o $@ $(all-objects) $(all-tests) \
		$(shell pkg-config --libs criterion) $(all-libraries)

# Module rule template, defining all the rules for the given module
define MODULE_RULE_TEMPLATE
include make-utils/module.mk
endef

# Define the rules of every module
$(foreach module,$(all-modules),$(eval $(call MODULE_RULE_TEMPLATE, $(module))))

test: $(TEST_NAME)
	@$(TEST_NAME) 2>&1 | grep -e "\[.*\]"
PHONY += test

clean:
	@rm -rf $(OUT_DIR)
PHONY += clean

re:
	@$(MAKE) clean
	@$(MAKE) all
PHONY += re

FORCE:
PHONY += FORCE

.PHONY: $(PHONY)
