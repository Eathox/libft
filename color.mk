# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    color.mk                                           :+:    :+:             #
#                                                      +:+                     #
#    By: pholster <pholster@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/02/15 18:10:25 by pholster       #+#    #+#                 #
#    Updated: 2020/02/15 18:10:25 by pholster      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

# Defines for easy color use
COLOR_DEFUALT := $(shell printf "\033[39m")
COLOR_BLACK := $(shell printf "\033[38;5;0m")
COLOR_RED := $(shell printf "\033[38;5;1m")
COLOR_GREEN := $(shell printf "\033[38;5;2m")
COLOR_YELLOW := $(shell printf "\033[38;5;3m")
COLOR_BLUE := $(shell printf "\033[38;5;4m")
COLOR_MAGENTA := $(shell printf "\033[38;5;5m")
COLOR_CYAN := $(shell printf "\033[38;5;6m")
COLOR_WHITE := $(shell printf "\033[38;5;7m")
COLOR_BRIGHT_BLACK := $(shell printf "\033[38;5;8m")
COLOR_BRIGHT_RED := $(shell printf "\033[38;5;9m")
COLOR_BRIGHT_GREEN := $(shell printf "\033[38;5;10m")
COLOR_BRIGHT_YELLOW := $(shell printf "\033[38;5;11m")
COLOR_BRIGHT_BLUE := $(shell printf "\033[38;5;12m")
COLOR_BRIGHT_MAGENTA := $(shell printf "\033[38;5;13m")
COLOR_BRIGHT_CYAN := $(shell printf "\033[38;5;14m")
COLOR_BRIGHT_WHITE := $(shell printf "\033[38;5;15m")
PRINT_MIN := $(shell printf '$(COLOR_RED)[ - ]$(COLOR_DEFUALT)')
PRINT_DEL := $(shell printf '$(COLOR_BRIGHT_YELLOW)[ ~ ]$(COLOR_DEFUALT)')
PRINT_PLUS := $(shell printf '$(COLOR_GREEN)[ + ]$(COLOR_DEFUALT)')
PRINT_EQUAL := $(shell printf '$(COLOR_BRIGHT_CYAN)[ = ]$(COLOR_DEFUALT)')

# Functions for easy terminal printing
FNC_PRINT_MIN = printf '$(PRINT_MIN) $(1): $(2)\n'
FNC_PRINT_DEL = printf '$(PRINT_DEL) $(1): $(2)\n'
FNC_PRINT_PLUS = printf '$(PRINT_PLUS) $(1): $(2)\n'
FNC_PRINT_EQUAL = printf '$(PRINT_EQUAL) $(1): $(2)\n'
