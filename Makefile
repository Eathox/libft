# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: pholster <pholster@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/01/07 20:00:45 by pholster       #+#    #+#                 #
#    Updated: 2019/02/08 16:04:11 by pholster      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

INCLUDES = ./includes/
NAME = libft.a
OBJ_NAME = objects

include $(INCLUDES)makefile.srcs

NORM = norminette $(LIBFT_SRCS) $(INCLUDES)libft.h $(INCLUDES)get_next_line.h \
	| grep -e "Error" -e "Warning" -B 1

TESTS = ./test/main.c $(LIBFT_SRCS:%=./test/test_%)
CCFLAGS = -Wall -Werror -Wextra -I$(INCLUDES)

all: $(NAME)

$(NAME): $(OBJ_NAME)
	@echo "creating libary"
	@ar rc $(NAME) $(LIBFT_OBJS)
	@echo "indexing libary"
	@ranlib $(NAME)

$(OBJ_NAME):
	@echo "compiling"
	@echo $(LIBFT_SRCS)
	@touch $(OBJ_NAME)
	@gcc $(CCFLAGS) -c $(LIBFT_SRCS)

clean:
	@echo "clean";
	@rm -f $(OBJ_NAME) $(LIBFT_OBJS) $(LIBFT_SRCS:.c=.c~)

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
