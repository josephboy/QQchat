CC = gcc
CFLAGS = -lmysqlclient -Wall -g
INC = -I/usr/include/mysql/ 


database : database.o
	$(CC) database.o -o database $(INC) $(CFLAGS)

database.o : src/database.c	inc/database.h
	$(CC) -c src/database.c -o database.o $(INC) $(CFLAGS) -I inc/




clean : 
	rm -rf *.o database


debug : src/database.c	inc/database.h
	$(CC) -g src/database.c -o database $(INC) $(CFLAGS) -I inc/


