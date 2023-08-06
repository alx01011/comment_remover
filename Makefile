CC=gcc
COPTS=-Wall -Wextra -pedantic

.PHONY: all comment_remover clean

all: comment_remover

comment_remover: src/comment_remove.c
	$(CC) $(COPTS) -o comment_remover $<

clean:
	rm -f comment_remover
