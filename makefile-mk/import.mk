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
$(module)-headers += $(patsubst %,$(HEADER_PATH)/%.h, $(module))
$(module)-objects += $(patsubst %,$(REG_CACHE_PATH)/$(module)/%.o, $(objects))
$(module)-tests += $(patsubst %,$(TEST_CACHE_PATH)/$(module)/%.o, $(tests))

all-libraries += $(libraries)
all-headers += $($(module)-headers)
all-objects += $($(module)-objects)
all-tests += $($(module)-tests)
