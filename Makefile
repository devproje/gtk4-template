CC = gcc
PKGCONFIG = $(shell which pkg-config)
CFLAGS = -Wall -Wextra $(shell $(PKGCONFIG) --cflags gtk4)
LIBS = $(shell $(PKGCONFIG) --libs gtk4)
OBJS = main.o
SRCS = $(OBJS:.o=.c)

OUTPUT = a.out

all: $(OUTPUT)

$(OUTPUT): $(OBJS)
	gcc -o $@ $^ $(CFLAGS) $(LIBS)

$(OBJS): $(SRCS)

clean:
	rm -f $(OBJS)
	rm -f $(OUTPUT)

.PHONY: all, clean

