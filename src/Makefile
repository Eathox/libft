# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: pholster <pholster@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/01/07 20:00:45 by pholster       #+#    #+#                 #
#    Updated: 2019/08/21 01:49:40 by pholster      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

# Input values from parent make
GCOV =
CCSILENT =
GCOVSILENT =
GCOVFLAGS =
CCOPTIMISE =
CCSTRICT =
NAME =
SRCFOLDER = $(NAME)
LIBNAME := $(NAME).a

SILENCE = 2>/dev/null 1>/dev/null

INCLUDES = ../includes
MAKEINCLUDES = $(INCLUDES)
include $(MAKEINCLUDES)/Makefile.color
include Makefile.subLibs

CCFLAGS = -g $(CCSTRICT) -I$(INCLUDES) $(CCOPTIMISE)
ifeq ($(GCOV), TRUE)
CCFLAGS += -coverage
endif

HEADERS := $(HEADERS:%=$(INCLUDES)/%)
SRCS := $(SRCS:%=$(SRCFOLDER)/ft_%.c)
SRCS := $(sort $(SRCS))
OBJS = $(SRCS:.c=.o)
TEMPS = $(SRCS:.c=.c~)
GCDAS = $(OBJS:.o=.gcda)
GCNOS = $(OBJS:.o=.gcno)
GCOVS = $(OBJS:.o=.c.gcov)
BASE_GCOVS = $(GCOVS:$(SRCFOLDER)/%=%)

GCOVREPORT = (gcov $(GCOVFLAGS) $(SRCS) && mv -f $(BASE_GCOVS) $(SRCFOLDER))
ifeq ($(GCOVSILENT), TRUE)
GCOVREPORT += $(SILENCE)
endif

TESTPATH = tests
TEST = $(TESTPATH)/libtest

all: $(LIBNAME)

ifeq ($(GCOV), TRUE)
$(LIBNAME): $(OBJS) $(GCNOS)
else
$(LIBNAME): $(OBJS)
endif
	@printf '$(PRINT_EQUAL) $(SRCFOLDER): $(LIBNAME)\n'
	@ar rcs $(LIBNAME) $(OBJS)

gcovreport: all
	$(call GCOVREPORT)

%.o %.gcno: %.c $(HEADERS)
ifeq ($(CCSILENT), FALSE)
	@printf '$(PRINT_PLUS) $(SRCFOLDER): $(shell basename $@)\n'
endif
	@rm -f $(<:.c=.o)
	@gcc $(CCFLAGS) -o $(<:.c=.o) -c $<

clean:
ifneq ($(wildcard $(OBJS) $(TEMPS) $(GCOVS) $(GCDAS) $(GCNOS)),)
	@printf '$(PRINT_MIN) $(SRCFOLDER): cleaning\n'
	@rm -f $(OBJS) $(TEMPS) $(GCOVS) $(GCDAS) $(GCNOS)
endif

re: clean all

FORCE: ;

.PHONY: clean re
