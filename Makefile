# CSE30 Makefile
# 
# EXE - objects we want to build
# OBJS - objects we want to compile (from c)
# 
# We provide a phony target clean to rm all the .o files
# 
# Run make to run with warnings
# Run make WARN= to run without warnings
# Run make DEBUG= to run without debug
# Run make DEBUG= WARN= to run without debug and warnings
# Run make clean to clean objects

EXE = tree_lookup
OBJS = tree_lookup.o parse_opts.o hash.o wrapper.o
CC = gcc
DEBUG = -g
WARN = -Wall -Wextra
CFLAGS = -I. -std=gnu11 $(DEBUG) $(WARN)
LDFLAGS = -Wl,--wrap=main,--wrap=malloc
LIBS = 

.PHONY: clean

$(EXE) : $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $(OBJS) $(LIBS)

tree_lookup.o: tree_lookup.h

clean:
	rm -f $(EXE) $(OBJS)
