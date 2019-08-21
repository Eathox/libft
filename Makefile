# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: pholster <pholster@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/01/07 20:00:45 by pholster       #+#    #+#                 #
#    Updated: 2019/08/21 21:21:47 by pholster      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

#Sublib folder names of libft
SUBLIBS = printf threadpool unsignednumber number numberarray float character \
	string stringarray utf8 memory list hash color terminal bool

#Libft name
NAME = libft.a

#Compile settings
CCSILENT = FALSE
CCSTRICT = -Wall -Werror -Wextra
CCOPTIMISE =

#Gcov settings
GCOV = FALSE
GCOVSILENT = TRUE
GCOVFLAGS = -f -b -c

#Mafile includes
MAKEINCLUDES = includes/
include $(MAKEINCLUDES)/Makefile.color

#Tests info
TESTPATH = tests
TEST = $(TESTPATH)/libtest

#Sublib info
SUBLIBS := $(sort $(SUBLIBS))
SUBLIBS := $(SUBLIBS:%=src/%.a)
SUBLIBMAKE = $(MAKE) -s -e -C src LIBNAME=$(NAME:%.a=%)

#Fclean target files
FCLEAN_FILES := $(wildcard $(NAME) $(SUBLIBS))

#Function - Get all objects of sublibs
GET_OBJS = $(shell ar -t $(1) | grep '\.o' | sed 's/^/$(1:src/%.a=src\/%\/)/g')
SUBLIBS_OBJS = $(foreach DIR,$(SUBLIBS),$(call GET_OBJS,$(DIR)))

#Function - Clean all sublib .a
CLEAN_SUBLIB = $(SUBLIBMAKE) NAME=$(1:src/%.a=%) clean &&
SUBLIBS_CLEAN = $(foreach DIR,$(SUBLIBS),$(call CLEAN_SUBLIB,$(DIR))) :

#Function - Clean all sublib .a
GCOV_SUBLIB = $(SUBLIBMAKE) NAME=$(1:src/%.a=%) gcovreport &&
SUBLIBS_GCOV = $(foreach DIR,$(SUBLIBS),$(call GCOV_SUBLIB,$(DIR))) :

#Export vars to sublib makefile
export GCOV
export GCOVSILENT
export GCOVFLAGS
export CCSILENT
export CCSTRICT
export CCOPTIMISE

all: $(NAME)

#Create NAME
$(NAME): $(SUBLIBS)
	@$(call FNC_PRINT_EQUAL,$(NAME:%.a=%),$(NAME))
	@ar rcs $(NAME) $(SUBLIBS_OBJS)

#Run test and gcov if GCOV==TRUE
test: $(NAME) FORCE
ifeq ($(wildcard $(TESTPATH)),)
	@echo "Error: $(TESTPATH) not present"
else
	@$(MAKE) -s -e -C $(TESTPATH)
	@./$(TEST)
ifeq ($(GCOV), TRUE)
	@$(SUBLIBS_GCOV)
endif
endif

#Compile SUBLIBS
src/%.a: FORCE
	@$(SUBLIBMAKE) NAME=$(@:src/%.a=%)

#Clean all non .a files
clean:
ifneq ($(wildcard $(TESTPATH)),)
	@$(MAKE) -s -C $(TESTPATH) clean
endif
	@$(SUBLIBS_CLEAN)

#Clean all .a files
fclean: clean
ifneq ($(wildcard $(TESTPATH)),)
	@$(MAKE) -s -C $(TESTPATH) fclean
endif
ifneq ($(FCLEAN_FILES),)
	@$(call FNC_PRINT_MIN,$(NAME:%.a=%),deleting $(FCLEAN_FILES:src/%=%))
	@rm -f $(NAME) $(SUBLIBS)
endif

#Recompile
re: fclean $(NAME)

FORCE: ;

.PHONY: all test clean fclean re
