CC = gcc
CFLAGS := $(shell pkg-config --cflags glib-2.0 gtk+-2.0 gmodule-2.0)
LDFLAGS := $(shell pkg-config --libs glib-2.0 gtk+-2.0 gmodule-2.0)
LIBS := -lsqlite3
DEBUG = -Wall
asitor: main.c includes/asitor.h
	$(CC) $(DEBUG) $(CFLAGS) $(LIBS) $< -o ../build/$@ $(LDFLAGS) 