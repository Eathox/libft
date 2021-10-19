# Defines for easy text manipulation
TXT_RESET := $(shell tput sgr0)
TXT_BOLD := $(shell tput bold)
TXT_DIM := $(shell tput dim)
TXT_UNDERLINE := $(shell tput smul)
TXT_UNDERLINE_OFF := $(shell tput rmul)

# Defines for easy color use
COLOR_RESET := $(shell tput init)
COLOR_BLACK := $(shell tput setaf 0)
COLOR_RED := $(shell tput setaf 1)
COLOR_GREEN := $(shell tput setaf 2)
COLOR_YELLOW := $(shell tput setaf 3)
COLOR_BLUE := $(shell tput setaf 4)
COLOR_MAGENTA := $(shell tput setaf 5)
COLOR_CYAN := $(shell tput setaf 6)
COLOR_WHITE := $(shell tput setaf 7)
COLOR_BRIGHT_BLACK := $(shell tput setaf 8)
COLOR_BRIGHT_RED := $(shell tput setaf 9)
COLOR_BRIGHT_GREEN := $(shell tput setaf 10)
COLOR_BRIGHT_YELLOW := $(shell tput setaf 11)
COLOR_BRIGHT_BLUE := $(shell tput setaf 12)
COLOR_BRIGHT_MAGENTA := $(shell tput setaf 13)
COLOR_BRIGHT_CYAN := $(shell tput setaf 14)
COLOR_BRIGHT_WHITE := $(shell tput setaf 15)

PRINT_MIN := $(shell printf '$(COLOR_RED)[ - ]$(COLOR_RESET)')
PRINT_PLUS := $(shell printf '$(COLOR_GREEN)[ + ]$(COLOR_RESET)')
PRINT_EQUAL := $(shell printf '$(COLOR_BRIGHT_CYAN)[ = ]$(COLOR_RESET)')
PRINT_GREATER := $(shell printf '$(COLOR_BRIGHT_YELLOW)[ > ]$(COLOR_RESET)')
PRINT_MISC := $(shell printf '$(COLOR_BRIGHT_WHITE)[ ~ ]$(COLOR_RESET)')

# Functions for easy terminal printing
FNC_PRINT = $(1) $(TXT_BOLD)$(2):$(TXT_RESET) $(3)
FNC_PRINT_MIN = echo '$(call FNC_PRINT,$(PRINT_MIN),$(1),$(2))'
FNC_PRINT_PLUS = echo '$(call FNC_PRINT,$(PRINT_PLUS),$(1),$(2))'
FNC_PRINT_EQUAL = echo '$(call FNC_PRINT,$(PRINT_EQUAL),$(1),$(2))'
FNC_PRINT_GREATER = echo '$(call FNC_PRINT,$(PRINT_GREATER),$(1),$(2))'
FNC_PRINT_MISC = echo '$(call FNC_PRINT,$(PRINT_MISC),$(1),$(2))'
