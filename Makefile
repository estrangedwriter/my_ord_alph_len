## QWASAR PROJECT, 2020
## my_ls
## File description: This C make file can help to build the my_ls program/executable.

## Setting the compiler
CC = gcc

## Setting the compile flag variables for gcc
CFLAGS = -g -Wall -Werror -Wextra 

## In this section, files that are part of the project are listed.
SOURCES = ordalphlong.c arrayfunctions.c sortfunctions.c
OBJECTS = $(SOURCES:.c=.o)
TARGET = my_ord_alph_len
LDFLAGS = 

# The first target defined in the makefile is the one
# used when make is invoked with no argument. Given the definitions
# above, this Makefile file will build the one named TARGET and
# assume that it depends on all the named OBJECTS files.
$(TARGET) : $(SOURCES)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

# Phony means not a "real" target, it doesn't build anything
# The phony target "clean" is used to remove all compiled object files.
.PHONY: clean
clean:
	@rm -f $(TARGET) $(OBJECTS) core

