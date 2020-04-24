# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    prefix.mk                                          :+:    :+:             #
#                                                      +:+                     #
#    By: pholster <pholster@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/02/15 18:10:11 by pholster      #+#    #+#                  #
#    Updated: 2020/02/15 18:10:11 by pholster      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

$(module)-objects := $(addprefix $(OUTDIR)/cache/reg/$(module)/, $(objects))
$(module)-tests := $(addprefix $(OUTDIR)/cache/test/$(module)/, $(tests))

all-libraries += $(libraries)
all-objects += $(addprefix $(OUTDIR)/cache/reg/$(module)/,$(objects))
all-tests += $(addprefix $(OUTDIR)/cache/test/$(module)/,$(tests))
