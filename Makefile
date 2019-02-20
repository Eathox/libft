# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: pholster <pholster@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/01/07 20:00:45 by pholster       #+#    #+#                 #
#    Updated: 2019/02/19 17:04:36 by pholster      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

INCLUDES = ./includes/
NAME = libft.a
OBJ_NAME = objects

SRCS = putchar putnbr putstr sqrt strcmp strdup strlen swap isalpha \
	isalnum isascii isprint toupper tolower putendl putchar_fd putstr_fd \
	putendl_fd putnbr_fd strnew strclr strdel striter striteri strmap \
	strmapi isspace itoa pow atoi strncmp strcpy strcat strequ strnequ \
	strncat strlcat strchr strrchr strstr strnstr strsub strjoin strtrim \
	strsplit memset bzero memcpy memdel memalloc memccpy memmove memcmp \
	strncpy lstnew lstdelone lstdel lstadd lstiter lstmap memchr isdigit \
	count_if foreach puterror toupperstr tolowerstr putline chrin chrnin \
	intin strin strnin putstrarr putintarr strndup strdlen wrddcount \
	chrtostr lstaddbck lstmemdel lsttostrarr strarrtolst lstlen strmatch \
	strrev lstdup lstdupone putstrlst putbool intarrtolst putintlst \
	lsttointarr min max constrain abs strreplace get_next_line clearterminal \
	strarrnew strarrdel itoa_base atoi_base isdigitstr strfieldnew chrindex \
	putpointer strdsplit putnbr_base strdtrim putnbr_fd_base putline_fd \
	isupper islower chrdin numlen_base numlen intlen intlen_base uintlen \
	uintlen_base unumlen unumlen_base strappend memdup lstunlink getchar \
	putnstr putnstr_fd strnlen strjoin_var

SRCS := $(SRCS:%=ft_%.c)
OBJS = $(SRCS:.c=.o)

NORM = norminette $(SRCS) $(INCLUDES)libft.h $(INCLUDES)get_next_line.h \
	| grep -e "Error" -e "Warning" -B 1

TESTS = ./test/main.c $(SRCS:%=./test/test_%)
CCFLAGS = -Wall -Werror -Wextra -I$(INCLUDES)

all: $(NAME)

$(NAME): $(OBJ_NAME)
	@echo "creating libary"
	@ar rc $(NAME) $(OBJS)
	@echo "indexing libary"
	@ranlib $(NAME)

$(OBJ_NAME):
	@echo "compiling"
	@echo $(SRCS)
	@touch $(OBJ_NAME)
	@gcc $(CCFLAGS) -c $(SRCS)

clean:
	@echo "clean";
	@rm -f $(OBJ_NAME) $(OBJS) $(SRCS:.c=.c~)

fclean: clean
	@echo "fclean";
	@rm -f $(NAME)

re: fclean $(NAME)

norm:
	@echo "-----------------------------------NormOutput\
-----------------------------------"
	@$(NORM) || true
	@echo "-----------------------------------End-Output\
-----------------------------------"
