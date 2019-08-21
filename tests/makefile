# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: pholster <pholster@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/01/07 20:00:45 by pholster       #+#    #+#                 #
#    Updated: 2019/08/21 16:58:31 by pholster      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

#Compile settings
CCSILENT = FALSE

#Test name
NAME = libtest

#Includes
INCLUDES = ../includes
MAKEINCLUDES = $(INCLUDES)
include $(MAKEINCLUDES)/Makefile.color

#Compile flags
CCFLAGS = -g -I$(INCLUDES) -I$(CRITERIONINCLUDES)
ifeq ($(shell uname -s), Linux)
CCFLAGS += -w
endif

#Get source files
include Makefile.testSrcs

#Lib dependency
LIBPATH = ../
LIBNAME = libft
LIB = $(LIBPATH)/$(LIBNAME).a

#Criterion install path
ifeq ($(shell uname -s), Linux)
INSTALLPATH := /usr
else
INSTALLPATH := $(shell brew --cellar)/..
endif

#Criterion dependency
CRITERIONINCLUDES = $(INSTALLPATH)/include
CRITERIONLIB = -L$(INSTALLPATH)/lib -lcriterion

#Header dependency
HEADERS := $(HEADERS:%=$(INCLUDES)/%) $(CRITERIONINCLUDES)

#Dependency prefix
SRCS := $(SRCS:%=src/test_ft_%.c)
SRCS := $(sort $(SRCS))
OBJS = $(SRCS:.c=.o)

#Trash files
TEMPS = $(SRCS:.c=.c~)

all: $(NAME)

#Create NAME
$(NAME): $(LIB) $(OBJS)
	@$(call FNC_PRINT_EQUAL,$(LIBNAME)-$(NAME:%.a=%),$(NAME))
	@$(CC) -coverage $(CCFLAGS) -o $(NAME) $(OBJS) $(LIB) $(CRITERIONLIB)
	#-Wl,-alias,_wrap_malloc,_malloc -Wl,-alias,_wrap_free,_free

#Compile .o
%.o: %.c $(HEADERS)
ifeq ($(CCSILENT), FALSE)
	@$(call FNC_PRINT_PLUS,$(LIBNAME)-$(NAME:%.a=%),$(shell basename $<))
endif
	@$(CC) $(CCFLAGS) -o $@ -c $<

#Create LIB
$(LIB):
	@make -s -C $(LIBPATH)

#Clean all non NAME files
clean:
ifneq ($(wildcard $(OBJS) $(TEMPS)),)
	@$(call FNC_PRINT_MIN,$(LIBNAME)-$(NAME:%.a=%),cleaning)
	@rm -f $(OBJS) $(TEMPS)
endif

#Clean NAME files
fclean: clean
ifneq ($(wildcard $(NAME)),)
	@$(call FNC_PRINT_MIN,$(LIBNAME)-$(NAME:%.a=%),deleting $(NAME))
	@rm -f $(NAME)
endif

#Recompile
re: fclean $(NAME)

FORCE: ;

.PHONY: all clean fclean re
