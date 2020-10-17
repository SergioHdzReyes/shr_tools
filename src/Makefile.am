bin_PROGRAMS = servers sync
servers_CPPFLAGS = -DDEBUG
servers_LDFLAGS = -lconfig -lcurl -lncurses -ltinfo
servers_SOURCES = servers.c	configuration.c screen_configs.c

sync_CPPFLAGS = -DDEBUG
sync_LDFLAGS = -lgit2
sync_SOURCES = sync.c
