# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: pholster <pholster@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/01/07 20:00:45 by pholster       #+#    #+#                 #
#    Updated: 2019/08/21 12:04:55 by pholster      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

#Sublib folder names of libft
SUBLIBS = string

#Compile settings
CCSILENT = FALSE
CCSTRICT = -Wall -Werror -Wextra
CCOPTIMISE =

#Gcov settings
GCOV = FALSE
GCOVSILENT = TRUE
GCOVFLAGS = -f -b -c

#Mafile includes
MAKEINCLUDES = includes/$(INCLUDES)
include $(MAKEINCLUDES)/Makefile.color

#Libft name
NAME = libft.a

#Tests info
TESTPATH = tests
TEST = $(TESTPATH)/libtest

#Sublib info
SUBLIBS := $(SUBLIBS:%=src/%.a)
SIBLIBMAKE = $(MAKE) -s -e -C src LIBNAME=$(NAME:%.a=%)

#Fclean target files
FCLEAN_FILES = $(wildcard $(NAME) $(SUBLIBS))

#Function - Get all objects of sublibs
GET_OBJS = $(shell ar -t $(1) | grep '\.o' | sed 's/^/$(1:src/%.a=src\/%\/)/g')
SUBLIBS_OBJS = $(foreach DIR,$(SUBLIBS),$(call GET_OBJS,$(DIR)))

#Function - Clean all sublib .a
CLEAN_SUBLIB = $(SIBLIBMAKE) NAME=$(SUBLIBS:src/%.a=%) clean
SUBLIBS_CLEAN = $(foreach DIR,$(SUBLIBS),$(CLEAN_SUBLIB))

#Export vars to sublib makefile
export GCOV
export GCOVSILENT
export GCOVFLAGS
export CCSILENT
export CCSTRICT
export CCOPTIMISE

all: $(NAME)

$(NAME): $(SUBLIBS)
	@printf '$(PRINT_EQUAL) $(NAME:%.a=%): $(NAME)\n'
	@ar rcs $(NAME) $(SUBLIBS_OBJS)

test: $(NAME) FORCE
ifeq ($(wildcard $(TESTPATH)),)
	@echo "Error: $(TESTPATH) not present"
else
	@$(MAKE) -s -e -C $(TESTPATH) LIBNAME=$(NAME:%.a=%)
	@./$(TEST)
ifeq ($(GCOV), TRUE)

endif
endif

src/%.a: FORCE
	@$(SIBLIBMAKE) NAME=$(@:src/%.a=%)

clean:
ifneq ($(wildcard $(TESTPATH)),)
	@$(MAKE) -s -C $(TESTPATH) LIBNAME=$(NAME:%.a=%) clean
endif
	@$(SUBLIBS_CLEAN)

fclean: clean
ifneq ($(FCLEAN_FILES),)
	@printf '$(PRINT_MIN) $(NAME:%.a=%): deleting $(FCLEAN_FILES:src/%=%)\n'
	@rm -f $(NAME) $(SUBLIBS)
endif
ifneq ($(wildcard $(TESTPATH)),)
	@$(MAKE) -s -C $(TESTPATH) LIBNAME=$(NAME:%.a=%) fclean
endif

re: fclean $(NAME)

FORCE: ;

.PHONY: test clean fclean re
