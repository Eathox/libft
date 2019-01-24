# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: pholster <pholster@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/01/07 20:00:45 by pholster       #+#    #+#                 #
#    Updated: 2019/01/24 11:43:07 by pholster      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRCS = putchar putnbr putstr sqrt strcmp strdup strlen swap isalpha \
	isalnum isascii isprint toupper tolower putendl putchar_fd putstr_fd \
	putendl_fd putnbr_fd strnew strclr strdel striter striteri strmap \
	strmapi isspace itoa pow atoi strncmp strcpy strcat strequ strnequ \
	strncat strlcat strchr strrchr strstr strnstr strsub strjoin strtrim \
	strsplit memset bzero memcpy memdel memalloc memccpy memmove memcmp \
	strncpy lstnew lstdelone lstdel lstadd lstiter lstmap memchr isdigit

SRCS += count_if foreach puterror toupperstr tolowerstr putline chrin \
	intin strin putstrarr putintarr intlen strndup strdlen wrddcount \
	chrtostr lstaddbck lstdelstr lsttostrarr strarrtolst lstlen strmatch \
	strrev lstdup lstdupone putstrlst putbool intarrtolst putintlst \
	lsttointarr min max constrain abs select strreplace get_next_line

SRCS := $(SRCS:%=ft_%.c)
OBJS = $(SRCS:.c=.o)

NORM = norminette $(SRCS) $(NAME:.a=.h) | grep -e "Error" -e "Warning" -B 1

TESTS = ./test/main.c $(SRCS:%=./test/test_%)

VPATH = ./srcs
INCLUDES = ./includes
CCFLAGS = -Wall -Werror -Wextra -I$(INCLUDES)

all: $(NAME)

$(NAME):
	@echo "compiling"
	@echo $(SRCS)
	@gcc $(CCFLAGS) -c $(SRCS)
	@echo "creating libary"
	@ar rc $(NAME) $(OBJS)
	@echo "indexing libary"
	@ranlib $(NAME)

clean:
	@echo "clean";
	@rm -f $(OBJS) $(SRCS:.c=.c~)

fclean: clean
	@echo "fclean";
	@rm -f $(NAME)

re: fclean $(NAME)

push:
ifdef MSG
	git add $(SRCS) ./includes/*.h Makefile author
	git commit -m "$(MSG)"
	git push
	@make norm
else
	@echo "error: define MSG"
endif

norm:
	@echo "-----------------------------------NormOutput\
-----------------------------------"
	@$(NORM) || true
	@echo "-----------------------------------End-Output\
-----------------------------------"
