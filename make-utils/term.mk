ESCAPE_PREFIX := \033[
ESCAPE_SUFFIX := m
ESCAPE = $(ESCAPE_PREFIX)$(1)$(ESCAPE_SUFFIX)

# Defines for easy text manipulation
TXT_RESET := $(shell printf "$(call ESCAPE,0)")
TXT_BOLD := $(shell printf "$(call ESCAPE,1)")
TXT_BOLD_OFF := $(shell printf "$(call ESCAPE,22)")
TXT_DIM := $(shell printf "$(call ESCAPE,2)")
TXT_DIM_OFF := $(shell printf "$(call ESCAPE,22)")
TXT_ITALIC := $(shell printf "$(call ESCAPE,3)")
TXT_ITALIC_OFF := $(shell printf "$(call ESCAPE,23)")
TXT_UNDERLINE := $(shell printf "$(call ESCAPE,4)")
TXT_UNDERLINE_OFF := $(shell printf "$(call ESCAPE,24)")

# Defines for easy color use
COLOR_RESET := $(shell printf "$(call ESCAPE,39)")
COLOR_BLACK := $(shell printf "$(call ESCAPE,38;5;0)")
COLOR_RED := $(shell printf "$(call ESCAPE,38;5;1)")
COLOR_GREEN := $(shell printf "$(call ESCAPE,38;5;2)")
COLOR_YELLOW := $(shell printf "$(call ESCAPE,38;5;3)")
COLOR_BLUE := $(shell printf "$(call ESCAPE,38;5;4)")
COLOR_MAGENTA := $(shell printf "$(call ESCAPE,38;5;5)")
COLOR_CYAN := $(shell printf "$(call ESCAPE,38;5;6)")
COLOR_WHITE := $(shell printf "$(call ESCAPE,38;5;7)")
COLOR_BRIGHT_BLACK := $(shell printf "$(call ESCAPE,38;5;8)")
COLOR_BRIGHT_RED := $(shell printf "$(call ESCAPE,38;5;9)")
COLOR_BRIGHT_GREEN := $(shell printf "$(call ESCAPE,38;5;10)")
COLOR_BRIGHT_YELLOW := $(shell printf "$(call ESCAPE,38;5;11)")
COLOR_BRIGHT_BLUE := $(shell printf "$(call ESCAPE,38;5;12)")
COLOR_BRIGHT_MAGENTA := $(shell printf "$(call ESCAPE,38;5;13)")
COLOR_BRIGHT_CYAN := $(shell printf "$(call ESCAPE,38;5;14)")
COLOR_BRIGHT_WHITE := $(shell printf "$(call ESCAPE,38;5;15)")

PRINT_MIN := $(shell printf '$(COLOR_RED)[ - ]$(COLOR_RESET)')
PRINT_PLUS := $(shell printf '$(COLOR_GREEN)[ + ]$(COLOR_RESET)')
PRINT_EQUAL := $(shell printf '$(COLOR_BRIGHT_CYAN)[ = ]$(COLOR_RESET)')
PRINT_RUN := $(shell printf '$(COLOR_BRIGHT_YELLOW)[ > ]$(COLOR_RESET)')
PRINT_MISC := $(shell printf '$(COLOR_BRIGHT_WHITE)[ ~ ]$(COLOR_RESET)')

# Functions for easy terminal printing
FNC_PRINT = $(1) $(TXT_BOLD)$(2):$(TXT_RESET) $(3)
FNC_PRINT_MIN = echo '$(call FNC_PRINT,$(PRINT_MIN),$(1),$(2))'
FNC_PRINT_PLUS = echo '$(call FNC_PRINT,$(PRINT_PLUS),$(1),$(2))'
FNC_PRINT_EQUAL = echo '$(call FNC_PRINT,$(PRINT_EQUAL),$(1),$(2))'
FNC_PRINT_RUN = echo '$(call FNC_PRINT,$(PRINT_RUN),$(1),$(2))'
FNC_PRINT_MISC = echo '$(call FNC_PRINT,$(PRINT_MISC),$(1),$(2))'
