# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    import.mk                                          :+:    :+:             #
#                                                      +:+                     #
#    By: pholster <pholster@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/02/15 18:10:11 by pholster      #+#    #+#                  #
#    Updated: 2020/02/15 18:10:11 by pholster      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

# Reset to be included variables
libraries :=
objects :=
tests :=

# Import the module's make.mk
include $(SRCDIR)/$(module)/make.mk

# Affix included variables
$(module)-headers += $(patsubst %,$(OUTDIR)/include/ft/%.h, $(module))
$(module)-objects += $(patsubst %,$(REG_CACHE_PATH)/$(module)/%.o, $(objects))
$(module)-tests += $(patsubst %,$(TEST_CACHE_PATH)/$(module)/%.o, $(tests))

all-public-headers += $($(module)-headers)
all-libraries += $(libraries)
all-objects += $($(module)-objects)
all-tests += $($(module)-tests)
