#PATH = $(shell pwd)
.PHONY : all

CC = gcc
CFLAGS = -W -Wall -pedantic -lmysqlclient -lpthread

OBJ_OUT = ./out
EXE_OUT = ./exe
DEBUG =

OBJ_SERVER = server.o

OBJ_CLIENT = client.o 
target = client server
ifndef DEBUG

.PHONY : QQ
QQ : ${target}

server : 
	gcc out/server.o -o server $(CFLAGS)

client :
	gcc out/client.o out/login.o out/database.o -o client $(CFLAGS)

.PHONY : socket
socket :
	make -C socket/

.PHONY : login
login :
	make -C login/

.PHONY : sql
sql :
	make -C SQL/


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
