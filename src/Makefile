# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: pholster <pholster@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/01/07 20:00:45 by pholster       #+#    #+#                 #
#    Updated: 2019/08/21 12:00:16 by pholster      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

#Input values for sublib (From parrent makefile)
NAME =
LIBNAME =

#Input values for compile (From parrent makefile)
CCSILENT =
CCSTRICT =
CCOPTIMISE =

#Input values for gcov (From parrent makefile)
GCOV =
GCOVSILENT =
GCOVFLAGS =

#Own names
SRCFOLDER = $(NAME)
SUBLIBNAME := $(NAME).a

#Misc setup
SILENCE = 2>/dev/null 1>/dev/null

#Includes
INCLUDES = ../includes
MAKEINCLUDES = $(INCLUDES)
include $(MAKEINCLUDES)/Makefile.color

#Get correct srcs variable
include Makefile.subLibs

#Compile flags
CCFLAGS = -g $(CCSTRICT) -I$(INCLUDES) $(CCOPTIMISE)
ifeq ($(GCOV), TRUE)
CCFLAGS += -coverage
endif

#Sublib dependencys
HEADERS := $(HEADERS:%=$(INCLUDES)/%)
SRCS := $(SRCS:%=$(SRCFOLDER)/ft_%.c)
SRCS := $(sort $(SRCS))
OBJS = $(SRCS:.c=.o)
GCNOS = $(OBJS:.o=.gcno)

#Trash files
TEMPS = $(SRCS:.c=.c~)
GCDAS = $(OBJS:.o=.gcda)
GCOVS = $(OBJS:.o=.c.gcov)

#Function - Gcov report
BASE_GCOVS = $(GCOVS:$(SRCFOLDER)/%=%)
GCOVREPORT = (gcov $(GCOVFLAGS) $(SRCS) && mv -f $(BASE_GCOVS) $(SRCFOLDER))
ifeq ($(GCOVSILENT), TRUE)
GCOVREPORT += $(SILENCE)
endif

all: $(SUBLIBNAME)

ifeq ($(GCOV), TRUE)
$(SUBLIBNAME): $(OBJS) $(GCNOS)
else
$(SUBLIBNAME): $(OBJS)
endif
	@printf '$(PRINT_EQUAL) $(LIBNAME)-$(SRCFOLDER): $(SUBLIBNAME)\n'
	@ar rcs $(SUBLIBNAME) $(OBJS)

gcovreport: all
	$(call GCOVREPORT)

%.o %.gcno: %.c $(HEADERS)
ifeq ($(CCSILENT), FALSE)
	@printf '$(PRINT_PLUS) $(LIBNAME)-$(SRCFOLDER): $(shell basename $@)\n'
endif
	@rm -f $(<:.c=.o)
	@gcc $(CCFLAGS) -o $(<:.c=.o) -c $<

clean:
ifneq ($(wildcard $(OBJS) $(TEMPS) $(GCOVS) $(GCDAS) $(GCNOS)),)
	@printf '$(PRINT_MIN) $(LIBNAME)-$(SRCFOLDER): cleaning\n'
	@rm -f $(OBJS) $(TEMPS) $(GCOVS) $(GCDAS) $(GCNOS)
endif

re: clean all

FORCE: ;

.PHONY: clean re
