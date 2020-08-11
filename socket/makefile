#PATH = $(shell pwd)
.PHONY : all

CC = gcc
CFLAGS = -W -Wall -pedantic

SRC = ./src
INC = ./inc
DEBUG =
target = server client

ifndef DEBUG

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


.PHONY : login
login :
	make -C login/


.PHONY : clean
clean : 
	rm -rf $(OBJ_OUT)/*.o server client a.out

else

test : test.o
	$(CC) test.o ${CFLAGS} -o test
test.o : ${SRC}/test.c
	$(CC) -c $(SRC)/test.c  -o test.o

.PHONY clean : 
	rm -rf *.o test a.out
endif
