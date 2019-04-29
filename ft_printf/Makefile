# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: pholster <pholster@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/01/07 20:00:45 by pholster       #+#    #+#                 #
#    Updated: 2019/04/29 16:02:21 by pholster      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

INCLUDES = ../includes/
NAME = libftprintf.a
OBJ_NAME = objects

SRCS = getinfo infosetdefualt formatpad formatbackpad addchar iszeropad addstr \
	isunsignint issignint setvar_type setvar_base infonew format formatnum \
	formatunum overflowsigned overflowunsigned addnstr addtobuff addnum \
	formatchar formatcolor addwchar formatstr addwcharstr getprecision \
	getwidth getflag getlength gettype ispositiveint isstr formatdouble \
	distribute setrgbcolorbg setrgbcolor commands setcolorbg setcolor addunum

SRCS := $(sort ft_strformat.c ft_dprintf.c ft_printf.c $(SRCS:%=pf_%.c))
OBJS = $(SRCS:.c=.o)

CCFLAGS = -Wall -Werror -Wextra -I$(INCLUDES)

all: $(NAME)

$(NAME):
	@echo "compiling libftprintf"
	@echo $(SRCS)
	@gcc $(CCFLAGS) -c $(SRCS)
	@echo "creating and indexing libftprintf"
	@ar rcs $(NAME) $(OBJS)

clean:
	@echo "cleaning libftprintf";
	@rm -f $(OBJS) $(SRCS:.c=.c~)

fclean: clean
	@echo "fcleaning libftprintf";
	@rm -f $(NAME)

re: fclean $(NAME)