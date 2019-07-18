# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: pholster <pholster@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/01/07 20:00:45 by pholster       #+#    #+#                 #
#    Updated: 2019/07/18 22:59:50 by pholster      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

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
LIBARY_OBJS = $(shell ar -t $(1) | grep '\.o' | sed 's/^/$(2:./%/=%\/)/g')

PRINTFPATH = ./ft_printf/
PRINTF = $(PRINTFPATH)libftprintf.a
PRINTF_OBJS = $(call LIBARY_OBJS,$(PRINTF),$(PRINTFPATH))

THREADPOOLPATH = ./threadpool/
THREADPOOL = $(THREADPOOLPATH)threadpool.a
THREADPOOL_OBJS = $(call LIBARY_OBJS,$(THREADPOOL),$(THREADPOOLPATH))

NAME = libft.a
INCLUDES = ./includes/
HEADERS = $(INCLUDES)libft.h $(INCLUDES)typedefs.h

SRCS = putchar putnbr putstr sqrt strcmp strdup strlen swap isalpha isalnum \
	isascii isprint toupper tolower putendl putchar_fd putstr_fd putendl_fd \
	putnbr_fd strnew strclr strdel striter striteri strmap strmapi isspace \
	itoa pow atoi strncmp strcpy strcat strequ strnequ strncat strlcat strchr \
	strrchr strstr strnstr strsub strjoin strtrim strsplit memset bzero memcpy \
	memdel memalloc memccpy memmove memcmp strncpy lstnew lstdelone lstdel \
	lstadd lstiter lstmap memchr isdigit count_if foreach puterror strtoupper \
	strtolower putline chrin chrnin intin strin strnin putstrarr putintarr \
	strndup strdlen wrddcount chrtostr lstaddbck lstdelmem lsttostrarr \
	strarrtolst lstlen strmatch strrev lstdup lstdupone putstrlst putbool \
	intarrtolst putintlst lsttointarr min max constrain abs memreplace \
	getnextline termclr strarrnew strarrdel itoa_base atoi_base \
	isdigitstr strfldnew chrindex putpointer strdsplit putnbr_base strdtrim \
	putnbr_base_fd putline_fd isupper islower chrdin numlen_base numlen intlen \
	intlen_base uintlen uintlen_base unumlen unumlen_base strappend memdup \
	lstunlink getchar putnstr putnstr_fd strnlen strjoin_var strarrlen \
	getnextdline chrdindex putnbr_cbase_fd putnbr_cbase lstfind_content \
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
	print_memory putnchar putnchar_fd pututf8str_fd memrchr strarrdup_var \
	strarrtolower strarrtoupper strindex strnindex normalize inrange \
	nearestnum strreplace colorrgbatohex colorhextorgba memindex
SRCS := $(SRCS:%=ft_%.c)

SRCS := $(sort $(SRCS))
OBJS = $(SRCS:.c=.o)

CCSILENT = FALSE
CCSTRICT = -Wall -Werror -Wextra
CCFLAGS = -g $(CCSTRICT) -I$(INCLUDES)

all: $(NAME)

$(NAME): $(PRINTF) $(THREADPOOL) $(OBJS)
	@printf '$(PRINT_EQUAL) $(NAME:%.a=%): $(NAME)\n'
	@ar rcs $(NAME) $(OBJS) $(PRINTF_OBJS) $(THREADPOOL_OBJS)

%.o: %.c $(HEADERS)
ifeq ($(CCSILENT), FALSE)
	@printf '$(PRINT_PLUS) $(NAME:%.a=%): $<\n'
endif
	@gcc $(CCFLAGS) -o $@ -c $<

$(PRINTF): FORCE
	@$(MAKE) -s -C $(PRINTFPATH)

$(THREADPOOL): FORCE
	@$(MAKE) -s -C $(THREADPOOLPATH)

clean:
ifneq ($(wildcard $(OBJS) $(SRCS:.c=.c~)),)
	@printf '$(PRINT_MIN) $(NAME:%.a=%): cleaning\n'
	@rm -f $(OBJS) $(SRCS:.c=.c~)
endif
	@$(MAKE) -s -C $(PRINTFPATH) clean
	@$(MAKE) -s -C $(THREADPOOLPATH) clean

fclean: clean
ifneq ($(wildcard $(NAME)),)
	@printf '$(PRINT_MIN) $(NAME:%.a=%): deleting $(NAME)\n'
	@rm -f $(NAME)
endif
	@$(MAKE) -s -C $(PRINTFPATH) fclean
	@$(MAKE) -s -C $(THREADPOOLPATH) fclean

re: fclean $(NAME)

FORCE: ;

.PHONY: clean fclean re
