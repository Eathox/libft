# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: pholster <pholster@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/01/07 20:00:45 by pholster       #+#    #+#                 #
#    Updated: 2019/08/22 00:17:05 by pholster      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

#Input values for sublib (From parrent makefile)
NAME =
FOLDER =
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
SRCFOLDER = $(NAME:%.a=%)
SUBLIB = $(FOLDER)/$(NAME)

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
include Makefile.$(SRCFOLDER)Srcs

#Dependency prefix
HEADERS := $(HEADERS:%=$(INCLUDES)/%)
HEADERS := $(sort $(HEADERS))
SRCS := $(FT_SRCS:%=$(SRCFOLDER)/ft_%.c) $(SRCS:%=$(SRCFOLDER)/$(PREFIX)_%.c)
SRCS := $(sort $(SRCS))

#Compile dependencys
OBJS = $(SRCS:.c=.o)
GCNOS = $(OBJS:.o=.gcno)
COMPILE_FILES = $(OBJS)
ifeq ($(GCOV), TRUE)
COMPILE_FILES += $(GCNOS)
endif

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

all: $(SUBLIB)

#Create $(SUBLIB)
$(SUBLIB): $(COMPILE_FILES)
	@$(call FNC_PRINT_EQUAL,$(LIBNAME)-$(SRCFOLDER),$(NAME))
	@ar rcs $(SUBLIB) $(OBJS)

#Run gcov
gcovreport: all
	$(GCOVREPORT)

#Compile .o or .gcno if $(GCOV)==TRUE
%.o %.gcno: %.c $(HEADERS)
ifeq ($(CCSILENT), FALSE)
	@$(call FNC_PRINT_PLUS,$(LIBNAME)-$(SRCFOLDER),$(shell basename $@))
endif
	@rm -f $(<:.c=.o)
	@$(CC) $(CCFLAGS) -o $(<:.c=.o) -c $<

#Clean all non .a files
clean:
ifneq ($(wildcard $(OBJS) $(TEMPS) $(GCOVS) $(GCDAS) $(GCNOS)),)
	@$(call FNC_PRINT_MIN,$(LIBNAME)-$(SRCFOLDER),clean)
	@rm -f $(OBJS) $(TEMPS) $(GCOVS) $(GCDAS) $(GCNOS)
endif

#Recompile
re: clean all

FORCE: ;

.PHONY: gcovreport all clean re
