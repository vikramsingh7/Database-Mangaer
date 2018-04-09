CC := gcc -Wall
OPTS := -Wall -ggdb

CFLAGS=-std=c99

main:
	$(CC) $(OPTS) $(LIBS) -o dbManager  main.c -pthread -std=c99

clean:
	@rm -f repl dbManager

.PHONY: clean wathc all
