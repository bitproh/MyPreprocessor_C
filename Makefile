CC = gcc
CFLAGS = -Wall -Wextra

mypreprocessor: main.o macro_handler.o file_inclusion.o comment_removal.o
	$(CC) $(CFLAGS) -o mypreprocessor main.o macro_handler.o file_inclusion.o comment_removal.o

main.o: main.c header.h
	$(CC) $(CFLAGS) -c main.c

macro_handler.o: macro_handler.c header.h
	$(CC) $(CFLAGS) -c macro_handler.c

file_inclusion.o: file_inclusion.c header.h
	$(CC) $(CFLAGS) -c file_inclusion.c

comment_removal.o: comment_removal.c header.h
	$(CC) $(CFLAGS) -c comment_removal.c

clear:
	@echo "cleaning up..."
	@rm -f *.o mypreprocessor

.PHONY: clear