CC = gcc
CFLAGS = -g -Wall -O0 -std=c99

SOURCES = my_mastermind.c
OBJECTS = $(SOURCES:.c=.o)
TARGET = mastermind


$(TARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)