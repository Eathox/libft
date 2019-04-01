# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: pholster <pholster@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/01/07 20:00:45 by pholster       #+#    #+#                 #
#    Updated: 2019/04/01 13:34:23 by pholster      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

INCLUDES = ../includes/
NAME = libftprintf.a
OBJ_NAME = objects

SRCS = getinfo infosetdefualt printpad printbackpad putchar iszeropad \
	putstr isunsignint issignint setvar_type setvar_base setvar_len \
	putinfo infonew print isnegative putnum putunum overflowsigned \
	overflowunsigned putnstr printchar setcolor commands putwchar \
	printstr putnutf8str getprecision getwidth getflag getlength gettype \
	iszero isnegativeint ispositiveint isstr printdouble getutf8strlen \
	getdoublelen getunsignedlen getsignedlen getstrlen distribute

SRCS := $(sort ft_dprintf.c ft_printf.c $(SRCS:%=pf_%.c))
OBJS = $(SRCS:.c=.o)

CCFLAGS = -Wall -Werror -Wextra -I$(INCLUDES)

NORM = norminette $(SRCS) $(HEADER) $(INCLUDES)$(LIBFT:.a=.h) \
	$(INCLUDES)get_next_line.h | grep -E '(Error:|Warning: [^N])' -B 1

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

norm:
	@echo "-----------------------------------NormOutput\
-----------------------------------"
	@$(NORM) || true
	@echo "-----------------------------------End-Output\
-----------------------------------"
