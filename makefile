#PATH = $(shell pwd)
.PHONY : all

CC = gcc
CFLAGS = -W -Wall -pedantic

OBJ_OUT = ./out
EXE_OUT = ./exe
DEBUG =

target = QQ

ifndef DEBUG

.PHONY : ${target}
${target} :
	$(CC) $(OBJ_OUT)/*.o  ${CFLAGS} -o ${target}

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
