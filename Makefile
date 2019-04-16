# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: pholster <pholster@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/01/07 20:00:45 by pholster       #+#    #+#                 #
#    Updated: 2019/04/16 12:24:51 by pholster      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

PRINTFPATH = ./ft_printf/
PRINTF = $(PRINTFPATH)libftprintf.a

INCLUDES = ./includes/
NAME = libft.a
OBJ_NAME = objects

SRCS = putchar putnbr putstr sqrt strcmp strdup strlen swap isalpha isalnum \
	isascii isprint toupper tolower putendl putchar_fd putstr_fd putendl_fd \
	putnbr_fd strnew strclr strdel striter striteri strmap strmapi isspace \
	itoa pow atoi strncmp strcpy strcat strequ strnequ strncat strlcat strchr \
	strrchr strstr strnstr strsub strjoin strtrim strsplit memset bzero memcpy \
	memdel memalloc memccpy memmove memcmp strncpy lstnew lstdelone lstdel \
	lstadd lstiter lstmap memchr isdigit count_if foreach puterror toupperstr \
	tolowerstr putline chrin chrnin intin strin strnin putstrarr putintarr \
	strndup strdlen wrddcount chrtostr lstaddbck lstdelmem lsttostrarr \
	strarrtolst lstlen strmatch strrev lstdup lstdupone putstrlst putbool \
	intarrtolst putintlst lsttointarr min max constrain abs strreplace \
	get_next_line termclr strarrnew strarrdel itoa_base atoi_base \
	isdigitstr strfldnew chrindex putpointer strdsplit putnbr_base strdtrim \
	putnbr_base_fd putline_fd isupper islower chrdin numlen_base numlen intlen \
	intlen_base uintlen uintlen_base unumlen unumlen_base strappend memdup \
	lstunlink getchar putnstr putnstr_fd strnlen strjoin_var strarrlen \
	get_next_dline chrdindex putnbr_cbase_fd putnbr_cbase lstfind_content \
	lstfind_size memrcpy lstlast strjoin_arr lstfindadd_content lstrev \
	lstfindadd_size strfldvalid memequ lstnlen strarrnlen strislen putlstsize \
	strarrrev intarrsort intarrsortrev lstsort lstsortrev strarrsort lstinsert \
	lstindex termsetcolor termsetcolorbg termresetcolor termresetcolorbg \
	strnequ_nocase strequ_nocase strncmp_nocase strmatchlen strcmp_nocase \
	colorcode strarrcpy colorncode colorlcode strmatchlen_nocase colorstr \
	termcommand termsetrgbcolorbg termsetrgbcolor pututf8 utf8len utf8strlen \
	utf8strnlen putnutf8str pututf8str putunbr_base putunbr_cbase putunbr_fd \
	putunbr_base_fd putunbr_cbase_fd putunbr strarrnsortrev strarrnsort \
	strarrsortrev intarrsortac strarrsortac lstsortstrac strarrcpy_var \
	strarrdup itoa_cbase putbytes chrsetbytes chrinbytes putdouble isblank \
	putdouble_fd putnutf8str_fd pututf8_fd pututf8str termcommand_fd \
	termclr_fd termresetcolorbg_fd termresetcolor_fd termsetrgbcolorbg_fd \
	termsetrgbcolor_fd termsetcolorbg_fd termsetcolor_fd putbool_fd readfile \
	print_memory putnchar putnchar_fd

SRCS := $(sort $(SRCS:%=ft_%.c))
OBJS = $(SRCS:.c=.o)

NORM = norminette $(SRCS) $(INCLUDES)libft.h $(INCLUDES)get_next_line.h \
	| grep -e "Error" -e "Warning" -B 1

TESTS = ./test/main.c $(SRCS:%=./test/test_%)
CCFLAGS = -Wall -Werror -Wextra -I$(INCLUDES)

all: $(NAME)

$(NAME): $(OBJ_NAME) $(PRINTF)
	@echo "indexing libft"
	@ar rcs $(NAME) $(OBJS)


$(OBJ_NAME):
	@echo "compiling libft"
	@echo $(SRCS)
	@touch $(OBJ_NAME)
	@gcc $(CCFLAGS) -c $(SRCS)

$(PRINTF):
	@make -C $(PRINTFPATH)
	@cp $(PRINTF) $(NAME)

test:
	@make re && make clean
	@gcc $(CCFLAGS) main.c libft.a

clean:
	@echo "cleaning libft";
	@rm -f $(OBJ_NAME) $(OBJS) $(SRCS:.c=.c~)
	@make -C $(PRINTFPATH) clean

fclean: clean
	@echo "fcleaning libft";
	@rm -f $(NAME)
	@make -C $(PRINTFPATH) fclean

re: fclean $(NAME)

norm:
	@echo "-----------------------------------NormOutput\
-----------------------------------"
	@$(NORM) || true
	@echo "-----------------------------------End-Output\
-----------------------------------"
