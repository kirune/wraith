# Makefile for src/mod/channels.mod/

srcdir = .
depcomp = /bin/sh ../../../build/autotools/depcomp

#This line is simply for configure to generate .deps/
OBJS = channels.o

include ./.deps/includes
include ../mod.mk

doofus:
	@echo ""
	@echo "Let's try this from the right directory..."
	@echo ""
	@cd ../../../ && make

static: ../channels.o

clean:
	@rm -f .depend *.o *~

distclean: clean

