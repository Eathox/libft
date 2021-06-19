# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: pholster <pholster@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/01/07 20:00:45 by pholster      #+#    #+#                  #
#    Updated: 2019/08/24 14:25:13 by pholster      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

SRCDIR := src

BASENAME := libft
NAME = $(OUTDIR)/$(BASENAME).a
TEST_NAME = $(OUTDIR)/test-$(BASENAME)

OS_NAME := $(shell uname -s)

# Include target modules
include make.mk

CFLAGS ?= -Wall -Wextra -Werror -Wpedantic -Wmissing-prototypes \
	-Wmissing-noreturn -MD

GCOV ?= false

# Disable optimizations since they can mess up the accuracy of the GCOV reports
# "The last -O option is the one that is effective."
ifeq ($(GCOV), true)
CFLAGS += --coverage -O0
endif

include makefile-mk/term.mk

OUTDIR ?= build
HEADER_PATH := $(OUTDIR)/include/ft
REG_CACHE_PATH := $(OUTDIR)/cache/reg
TEST_CACHE_PATH := $(OUTDIR)/cache/test

all-libraries :=
all-headers :=
all-objects :=
all-tests :=

# Module import template, importing the makefile of the given module
define MODULE_IMPORT_TEMPLATE
include makefile-mk/import.mk
endef

# Import each modules makefile specifying objects and tests
$(foreach module,$(modules),$(eval $(call MODULE_IMPORT_TEMPLATE, $(module))))

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
include makefile-mk/module.mk
endef

# Define the rules of every module
$(foreach module,$(modules),$(eval $(call MODULE_RULE_TEMPLATE, $(module))))

test: $(TEST_NAME)
	@$(TEST_NAME)
PHONY += test

clean:
	@rm -rf $(OUTDIR)
PHONY += clean

re:
	@$(MAKE) clean
	@$(MAKE) all
PHONY += re

FORCE:
PHONY += FORCE

.PHONY: $(PHONY)
