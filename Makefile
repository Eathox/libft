# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: pholster <pholster@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/01/07 20:00:45 by pholster       #+#    #+#                 #
#    Updated: 2019/08/21 01:53:53 by pholster      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

GCOV = FALSE
CCSILENT = FALSE
GCOVSILENT = TRUE

GCOVFLAGS = -f -b -c
CCOPTIMISE =
CCSTRICT = -Wall -Werror -Wextra

MAKEINCLUDES = includes/$(INCLUDES)
include $(MAKEINCLUDES)/Makefile.color

NAME = libft.a
TESTPATH = tests
TEST = $(TESTPATH)/libtest

SUBLIBS = string
SUBLIBS := $(SUBLIBS:%=src/%.a)

export GCOV
export GCOVSILENT
export GCOVFLAGS
export CCSILENT
export CCSTRICT
export CCOPTIMISE

all: $(NAME)

$(NAME): $(SUBLIBS)
	@printf '$(PRINT_EQUAL) $(NAME:%.a=%): $(NAME)\n'
	@ar rcs $(NAME)

test: $(NAME) FORCE
ifeq ($(wildcard $(TESTPATH)),)
	@echo "Error: $(TESTPATH) not present"
else
	@$(MAKE) -s -e -C $(TESTPATH)
	@./$(TEST)
ifeq ($(GCOV), TRUE)

endif
endif

src/%.a: FORCE
	@make -s -e -C src NAME=$(@:src/%.a=%)

clean:
ifneq ($(wildcard $(TESTPATH)),)
	@$(MAKE) -s -C $(TESTPATH) clean
endif

fclean: clean
ifneq ($(wildcard $(NAME)),)
	@printf '$(PRINT_MIN) $(NAME:%.a=%): deleting $(NAME)\n'
	@rm -f $(NAME)
endif
ifneq ($(wildcard $(TESTPATH)),)
	@$(MAKE) -s -C $(TESTPATH) fclean
endif

re: fclean $(NAME)

FORCE: ;

.PHONY: test clean fclean re
