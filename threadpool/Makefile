# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: pholster <pholster@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/01/07 20:00:45 by pholster       #+#    #+#                 #
#    Updated: 2019/04/22 15:02:50 by pholster      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

INCLUDES = ../includes/
NAME = libpool.a
OBJ_NAME = objects

SRCS = pooldone poolcreate pooldelete poolque threadmanager pooljoin

SRCS := $(sort $(SRCS:%=ft_%.c))
OBJS = $(SRCS:.c=.o)

CCFLAGS = -Wall -Werror -Wextra -I$(INCLUDES)

NORM = norminette $(SRCS) $(HEADER) $(INCLUDES)$(LIBFT:.a=.h) \
	$(INCLUDES)threadpool.h | grep -E '(Error:|Warning: [^N])' -B 1

all: $(NAME)

$(NAME):
	@echo "compiling threadpool"
	@echo $(SRCS)
	@gcc $(CCFLAGS) -c $(SRCS)
	@echo "creating and indexing threadpool"
	@ar rcs $(NAME) $(OBJS)

clean:
	@echo "cleaning threadpool";
	@rm -f $(OBJS) $(SRCS:.c=.c~)

fclean: clean
	@echo "fcleaning threadpool";
	@rm -f $(NAME)

re: fclean $(NAME)

norm:
	@echo "-----------------------------------NormOutput\
-----------------------------------"
	@$(NORM) || true
	@echo "-----------------------------------End-Output\
-----------------------------------"
