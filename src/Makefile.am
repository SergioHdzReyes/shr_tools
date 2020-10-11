bin_PROGRAMS = servers sync
servers_CPPFLAGS = -DDEBUG -std=c18
servers_LDFLAGS = -lconfig -lcurl
servers_SOURCES = servers.c src/configuration.h

sync_CPPFLAGS = -DDEBUG -std=c18
sync_LDFLAGS = -lgit2
sync_SOURCES = sync.c
