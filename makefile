#PATH = $(shell pwd)
.PHONY : all

CC = gcc
CFLAGS = -W -Wall -pedantic

SRC = ./socket/src
INC = ./socket/inc
OUT = ./out
TEST =
target = server client

ifndef TEST



server : server.o
	$(CC)  $(OUT)/server.o -o server
server.o : $(SRC)/server.c $(INC)/server.h
	$(CC) -c $(SRC)/server.c -o $(OUT)/server.o -I $(INC)

client : client.o
	$(CC)  $(OUT)/client.o -o client 
client.o : $(SRC)/client.c $(INC)/client.h
	$(CC) -c $(SRC)/client.c -o $(OUT)/client.o -I $(INC)

all : $(target)

clean : 
	rm -rf $(OUT)/*.o server client a.out

else

test : test.o
	$(CC) test.o ${CFLAGS} -o test
test.o : ${SRC}/test.c
	$(CC) -c $(SRC)/test.c  -o test.o

clean : 
	rm -rf *.o test a.out
endif