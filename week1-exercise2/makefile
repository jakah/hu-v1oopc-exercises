#############################################################################
#
# Project Makefile
#
# (c) Wouter van Ooijen (www.voti.nl) 2016
#
# This file is in the public domain.
#
#############################################################################

# source files in this project (main.cpp is automatically assumed)
SOURCES := line.cpp circle.cpp rectangle.cpp window.cpp train.cpp

# header files in this project
HEADERS := main.hpp line.hpp circle.hpp rectangle.hpp window.hpp train.hpp

# other places to look for files for this project
SEARCH  :=

# set RELATIVE to the next higher directory
# and defer to the Makefile.* there
RELATIVE := ..
include $(RELATIVE)/Makefile.native

LDFLAGS = -lSDL2
