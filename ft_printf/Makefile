# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: pholster <pholster@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/01/07 20:00:45 by pholster       #+#    #+#                 #
#    Updated: 2019/08/17 15:27:22 by pholster      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

CCSILENT = FALSE
GCOV = FALSE

COLOR_DEFUALT := $(shell printf "\e[39m")
COLOR_BLACK := $(shell printf "\e[38;5;0m")
COLOR_RED := $(shell printf "\e[38;5;1m")
COLOR_GREEN := $(shell printf "\e[38;5;2m")
COLOR_YELLOW := $(shell printf "\e[38;5;3m")
COLOR_BLUE := $(shell printf "\e[38;5;4m")
COLOR_MAGENTA := $(shell printf "\e[38;5;5m")
COLOR_CYAN := $(shell printf "\e[38;5;6m")
COLOR_WHITE := $(shell printf "\e[38;5;7m")
COLOR_BRIGHT_BLACK := $(shell printf "\e[38;5;8m")
COLOR_BRIGHT_RED := $(shell printf "\e[38;5;9m")
COLOR_BRIGHT_GREEN := $(shell printf "\e[38;5;10m")
COLOR_BRIGHT_YELLOW := $(shell printf "\e[38;5;11m")
COLOR_BRIGHT_BLUE := $(shell printf "\e[38;5;12m")
COLOR_BRIGHT_MAGENTA := $(shell printf "\e[38;5;13m")
COLOR_BRIGHT_CYAN := $(shell printf "\e[38;5;14m")
COLOR_BRIGHT_WHITE := $(shell printf "\e[38;5;15m")
PRINT_MIN := $(shell printf '$(COLOR_RED)[ - ]$(COLOR_DEFUALT)')
PRINT_PLUS := $(shell printf '$(COLOR_GREEN)[ + ]$(COLOR_DEFUALT)')
PRINT_EQUAL := $(shell printf '$(COLOR_BRIGHT_CYAN)[ = ]$(COLOR_DEFUALT)')

NAME = libftprintf.a
INCLUDES = ../includes
HEADERS = ft_printf.h typedefs.h
HEADERS := $(HEADERS:%=$(INCLUDES)/%)

PREFIX = pf
FT_SRCS = strformat strformat_len dprintf printf
SRCS = getinfo infosetdefault formatpad formatbackpad addchar iszeropad addstr \
	isunsignint issignint setvar_type setvar_base infonew format formatnum \
	formatunum overflowsigned overflowunsigned addnstr addtobuff addnum \
	formatchar formatcolor addwchar formatstr addwcharstr getprecision \
	getwidth getflag getlength gettype ispositiveint isstr formatdouble \
	distribute setrgbcolorbg setrgbcolor commands setcolorbg setcolor addunum
SRCS := $(FT_SRCS:%=src/ft_%.c) $(SRCS:%=src/$(PREFIX)_%.c)

SRCS := $(sort $(SRCS))
OBJS = $(SRCS:.c=.o)
GCOVS = $(OBJS:.o=.c.gcov)
GCDAS = $(OBJS:.o=.gcda)
GCNOS = $(OBJS:.o=.gcno)

CCOPTIMISE =
CCSTRICT = -Wall -Werror -Wextra
CCFLAGS = -g $(CCSTRICT) -I$(INCLUDES) $(CCOPTIMISE)
ifeq ($(GCOV), TRUE)
CCFLAGS += -coverage
endif

all: $(NAME)

$(NAME): $(OBJS)
	@printf '$(PRINT_EQUAL) $(NAME:%.a=%): $(NAME)\n'
	@ar rcs $(NAME) $(OBJS)

%.o: %.c $(HEADERS)
ifeq ($(CCSILENT), FALSE)
	@printf '$(PRINT_PLUS) $(NAME:%.a=%): $(shell basename $<)\n'
endif
	@gcc $(CCFLAGS) -o $@ -c $<

clean:
ifneq ($(wildcard $(OBJS) $(SRCS:.c=.c~) $(GCOVS) $(GCDAS) $(GCNOS)),)
	@printf '$(PRINT_MIN) $(NAME:%.a=%): cleaning\n'
	@rm -f $(OBJS) $(SRCS:.c=.c~) $(GCOVS) $(GCDAS) $(GCNOS)
endif

fclean: clean
ifneq ($(wildcard $(NAME)),)
	@printf '$(PRINT_MIN) $(NAME:%.a=%): deleting $(NAME)\n'
	@rm -f $(NAME)
endif

re: fclean $(NAME)

.PHONY: clean fclean re
