CC=gcc
EXE=check_credentials
CFLAGS=-Wall
LDFLAGS=
LIBS=-lcrypt
VERSION=$(shell cat VERSION)

PREFIX?=/usr/local
INSTALL_BIN=$(PREFIX)/sbin

DEBUG?=false
ifeq ($(DEBUG), true)
    CFLAGS+=-ggdb -DDEBUG
endif

SRC=$(EXE).c
OBJ=$(SRC:.c=.o)

$(EXE):
	$(CC) $(CFLAGS) $(SRC) -o $@ $(LDFLAGS) $(LIBS)

clean:
	rm -f $(EXE)

install: $(EXE)
	install -m 0755 $(EXE) $(INSTALL_BIN)

.PHONY: install
