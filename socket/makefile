#PATH = $(shell pwd)
.PHONY : all

CC = gcc
CFLAGS = -W -Wall -pedantic
OBJ_OUT = ../out
SRC = ./src
INC = ./inc
LOGIN_INC = ../login
DEBUG =
OBJ = server.o client.o

ifndef DEBUG
target : $(OBJ)

server.o : $(SRC)/server.c $(INC)/server.h
	$(CC) -c $(SRC)/server.c -o $(OBJ_OUT)/server.o -I $(INC) -lpthread $(CFLAGS)

client.o : $(SRC)/client.c $(INC)/client.h ../login/inc/login.h ../SQL/inc/database.h 
	$(CC) -c $(SRC)/client.c -o $(OBJ_OUT)/client.o -I $(INC) -I ../login/inc/ -I ../SQL/inc/ -lpthread $(CFLAGS)


else
all : $(target)

server : server.o
	echo $(OBJ_OUT)
	$(CC)  $(OBJ_OUT)/server.o -o server -lpthread
server.o : $(SRC)/server.c $(INC)/server.h
	$(CC) -c $(SRC)/server.c -o $(OBJ_OUT)/server.o -I $(INC) -lpthread

client : client.o
	$(CC)  $(OBJ_OUT)/client.o -o client  -lpthread
client.o : $(SRC)/client.c $(INC)/client.h
	$(CC) -c $(SRC)/client.c -o $(OBJ_OUT)/client.o -I $(INC) -lpthread

endif


.PHONY : clean
clean : 
	rm -rf $(OBJ_OUT)/*.o server client a.out