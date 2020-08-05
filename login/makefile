CC = gcc
CFLAGS += -lmysqlclient -Wall -g
INC = -I/usr/include/mysql/ 
DEBUG = 

login : login.o database.o
	$(CC) login.o database.o -o login $(INC) $(CFLAGS) -I inc/ 

login.o : src/login.c	inc/login.h
	$(CC) -c src/login.c -o login.o $(INC) $(CFLAGS) -I inc/ -I ../SQL/inc/

database.o : ../SQL/src/database.c ../SQL/inc/database.h
	$(CC) -c ../SQL/src/database.c -o database.o $(INC) $(CFLAGS) -I ../SQL/inc/

.PHONY clean : 
	rm -rf *.o login

