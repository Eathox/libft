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
modules :=
objects :=
tests :=

# Import the module's make.mk
include $(SRCDIR)/$(module)/make.mk

# Affix included variables
$(module)-modules += $(patsubst %,$(module)/%, $(modules))
$(module)-headers += $(patsubst %,$(HEADER_PATH)/%.h, $(module))
$(module)-objects += $(patsubst %,$(REG_CACHE_PATH)/$(module)/%.o, $(objects))
$(module)-tests += $(patsubst %,$(TEST_CACHE_PATH)/$(module)/%.o, $(tests))

all-libraries += $(libraries)
all-modules += $($(module)-modules)
all-headers += $($(module)-headers)
all-objects += $($(module)-objects)
all-tests += $($(module)-tests)

# Import newly added modules
$(foreach module,$($(module)-modules),$(eval $(call MODULE_IMPORT_TEMPLATE, $(module))))
