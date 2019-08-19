# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: pholster <pholster@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/01/07 20:00:45 by pholster       #+#    #+#                 #
#    Updated: 2019/08/19 18:08:35 by pholster      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

GET_OBJS = $(shell ar -t $(1) | grep '\.o' | sed 's/^/$(2:%=%\/src\/)/g')
ifeq ($(shell uname -s), Linux)
BREW := /usr
else
BREW := $(shell brew --cellar)/..
endif

LIBFTPATH = ../
LIBFT = $(LIBFTPATH)/libft.a

CRITERIONINCLUDES = $(BREW)/include
CRITERIONLIB = -L$(BREW)/lib -lcriterion

NAME = libtest
INCLUDES = ../includes
HEADERS = $(NAME).h
HEADERS := $(HEADERS:%=$(INCLUDES)/%) $(CRITERIONINCLUDES)

include $(INCLUDES)/Makefile.color

SRCS = abs atoi_base bzero hashmapnew hashsdbm hashdjb
SRCS := $(SRCS:%=test_ft_%.c) #wr_malloc.c

SRCS := $(sort $(SRCS))
OBJS = $(SRCS:.c=.o)

CCSILENT = FALSE
CCFLAGS = -g -I$(INCLUDES) -I$(CRITERIONINCLUDES)
ifeq ($(shell uname -s), Linux)
CCFLAGS += -w
endif

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@printf '$(PRINT_EQUAL) $(NAME:%.a=%): $(NAME)\n'
	@gcc -coverage $(CCFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(CRITERIONLIB)
	@ #-Wl,-alias,_wrap_malloc,_malloc -Wl,-alias,_wrap_free,_free

%.o: %.c $(HEADERS)
ifeq ($(CCSILENT), FALSE)
	@printf '$(PRINT_PLUS) $(NAME:%.a=%): $(shell basename $<)\n'
endif
	@gcc $(CCFLAGS) -o $@ -c $<

$(LIBFT):
	@make -s -C $(LIBFTPATH)

clean:
ifneq ($(wildcard $(OBJS) $(SRCS:.c=.c~)),)
	@printf '$(PRINT_MIN) $(NAME:%.a=%): cleaning\n'
	@rm -f $(OBJS) $(SRCS:.c=.c~)
endif

fclean: clean
ifneq ($(wildcard $(NAME)),)
	@printf '$(PRINT_MIN) $(NAME:%.a=%): deleting $(NAME)\n'
	@rm -f $(NAME)
endif

re: fclean $(NAME)

FORCE: ;

.PHONY: clean fclean re
