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

SRCDIR = src
OUTDIR ?= build

CFLAGS += -g -MD
CFLAGS += -Wall -Wextra -Werror
CFLAGS += -Wpedantic -Wmissing-prototypes -Wmissing-noreturn
INCLUDE += -I$(OUTDIR)/include

BASENAME = libft
NAME = $(OUTDIR)/$(BASENAME).a
TESTNAME = $(OUTDIR)/test-$(BASENAME)

MODULES += types
MODULES += printf
MODULES += thpool
MODULES += unum
MODULES += num
MODULES += numarr
MODULES += float
MODULES += char
MODULES += str
MODULES += strarr
MODULES += utf8
MODULES += mem
MODULES += list
MODULES += hash
MODULES += color
MODULES += term
MODULES += bool
MODULES += serialize

include makefile_mk/color.mk

all-libraries :=
all-objects :=
all-tests :=

# Module import template, importing the makefile of the given module
define MODULE_IMPORT_TEMPLATE
include makefile_mk/reset.mk $(SRCDIR)/$(module)/makefile makefile_mk/prefix.mk
endef

# Import each modules makefile specifying objects and tests
$(foreach module,$(MODULES),$(eval $(call MODULE_IMPORT_TEMPLATE, $(module))))

all-public-headers := $(patsubst %,$(OUTDIR)/include/ft/%.h, $(MODULES))

all: $(NAME)
PHONY += all

$(NAME): $(all-public-headers) $(all-objects)
	@mkdir -p $(dir $@)
	@$(call FNC_PRINT_EQUAL,$(BASENAME),$(notdir $@))
	@ar rcs $@ $(all-objects)

$(TESTNAME): $(all-public-headers) $(all-objects) $(all-tests)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDE) -o $@ $(all-objects) $(all-tests) \
		$(shell pkg-config --libs criterion) $(all-libraries)

# Module rule template, defining all the rules for the given module
define MODULE_RULE_TEMPLATE
include makefile_mk/module.mk
endef

# Define the rules of every module
$(foreach module,$(MODULES),$(eval $(call MODULE_RULE_TEMPLATE, $(module))))

test: $(TESTNAME)
	@$(TESTNAME)
PHONY += test

clean:
	@rm -rf $(OUTDIR)/cache
PHONY += clean

fclean: clean
	@rm -rf $(OUTDIR)
PHONY += fclean

re:
	@$(MAKE) fclean
	@$(MAKE) all
PHONY += re

FORCE:
PHONY += FORCE

.PHONY: $(PHONY)
.SECONDARY:
