# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: pholster <pholster@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/01/07 20:00:45 by pholster       #+#    #+#                 #
#    Updated: 2019/08/24 14:25:13 by pholster      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

OUTDIR ?= build
CFLAGS += -Wall -Wextra -Wpedantic -Werror -g
INCLUDE += -I$(OUTDIR)/include

NAME = $(OUTDIR)/libft.a
BASENAME = libft

MODULES = 	\
	types \
	printf \
	thpool \
	unum \
	num \
	numarr \
	float \
	char \
	str \
	strarr \
	utf8 \
	mem \
	list \
	hash \
	color \
	term \
	bool \

include color.mk

all-public-headers :=
all-objects :=
all-tests :=

define INCLUDE_TEMPLATE
module := $(1)
include reset.mk $(module)/Makefile prefix.mk
endef

$(foreach module,$(MODULES),$(eval $(call INCLUDE_TEMPLATE, $(module))))

all-makefiles := $(addsuffix /Makefile,$(MODULES))
all-public-headers := $(patsubst %,$(OUTDIR)/include/ft/%.h,$(MODULES))
all-objects := $(addprefix $(OUTDIR)/cache/reg/,$(all-objects))
all-tests := $(addprefix $(OUTDIR)/cache/test/,$(all-tests))

all: $(NAME)
PHONY += all

$(NAME): $(all-objects) $(all-makefiles)
	@mkdir -p $(dir $@)
	@$(call FNC_PRINT_EQUAL,$(BASENAME),$(notdir $@))
	@ar rcs $@ $(filter-out $(all-makefiles),$^)

define COMPILE_TEMPLATE
module := $(patsubst $(OUTDIR)/cache/reg/%/,%,$(dir $(1)))
include build_objects.mk
endef

$(foreach obj,$(all-objects),$(eval $(call COMPILE_TEMPLATE, $(obj))))

$(OUTDIR)/test-$(BASENAME): $(all-objects) $(all-tests) $(all-makefiles)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDE) $(shell pkg-config --libs criterion) -o $@ $(filter-out $(all-makefiles),$^)

define TEST_TEMPLATE
module := $(patsubst $(OUTDIR)/cache/test/%/,%,$(dir $(1)))
include build_test.mk
endef

$(foreach test,$(all-tests),$(eval $(call TEST_TEMPLATE, $(test))))

define HEADER_TEMPLATE
module := $(patsubst %.h,%,$(notdir $(1)))
include header.mk
endef

$(foreach header,$(all-public-headers),$(eval $(call HEADER_TEMPLATE, $(header))))

test: $(OUTDIR)/test-$(BASENAME)
	@$(OUTDIR)/test-$(BASENAME)
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

.PHONY: $(PHONY)
.SECONDARY:
