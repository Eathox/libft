# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: pholster <pholster@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/01/07 20:00:45 by pholster       #+#    #+#                 #
#    Updated: 2019/08/21 14:27:33 by pholster      ########   odam.nl          #
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
SUBLIBNAME = $(NAME).a

#Misc setup
SILENCE = 2>/dev/null 1>/dev/null

#Includes
INCLUDES = ../includes
MAKEINCLUDES = $(INCLUDES)
include $(MAKEINCLUDES)/Makefile.color

#Compile flags
CCFLAGS = -g $(CCSTRICT) -I$(INCLUDES) $(CCOPTIMISE)
ifeq ($(GCOV), TRUE)
CCFLAGS += -coverage
endif

#Get correct srcs variable
include Makefile.subLibs

#Dependency prefix
HEADERS := $(HEADERS:%=$(INCLUDES)/%)
SRCS := $(SRCS:%=$(SRCFOLDER)/ft_%.c)
SRCS := $(sort $(SRCS))

#Compile dependencys
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

#Create SUBLIBNAME
ifeq ($(GCOV), TRUE)
$(SUBLIBNAME): $(OBJS) $(GCNOS)
else
$(SUBLIBNAME): $(OBJS)
endif
	@$(call FNC_PRINT_EQUAL,$(LIBNAME)-$(SRCFOLDER),$(SUBLIBNAME))
	@ar rcs $(SUBLIBNAME) $(OBJS)

#Run gcov
gcovreport: all
	$(call GCOVREPORT)

#Compile .o or .gcno if GCOV==TRUE
%.o %.gcno: %.c $(HEADERS)
ifeq ($(CCSILENT), FALSE)
	@$(call FNC_PRINT_PLUS,$(LIBNAME)-$(SRCFOLDER),$(shell basename $@))
endif
	@rm -f $(<:.c=.o)
	@$(CC) $(CCFLAGS) -o $(<:.c=.o) -c $<

#Clean all non .a files
clean:
ifneq ($(wildcard $(OBJS) $(TEMPS) $(GCOVS) $(GCDAS) $(GCNOS)),)
	@$(call FNC_PRINT_MIN,$(LIBNAME)-$(SRCFOLDER),cleaning)
	@rm -f $(OBJS) $(TEMPS) $(GCOVS) $(GCDAS) $(GCNOS)
endif

#Recompile
re: clean all

FORCE: ;

.PHONY: clean re
