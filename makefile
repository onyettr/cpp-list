CC		=g++
LINK  		=g++
DEBUG 		=-g
CFLAGS		=-c -Wall -pedantic -DDEBUG_TRACE
LFLAGS		=

CHECK		= cppcheck
CHECK_FLAGS	= --language=c++ --enable=all

# -DDEBUG_TRACE	Will turn on deep trace per function
# -DEXCEPTION	Will use the real exceptions with the 'try' that's in the test harness

OBJS  = main.o list.o poortool.o test_add.o

all:	list.exe splint-me

list.exe:	$(OBJS)
	$(LINK) $(LFLAGS) $(OBJS) -o list.exe

main.o:		main.cpp
	$(CC) $(CFLAGS) $(DEBUG) main.cpp -o main.o
list.o:	list.cpp list.h
	$(CC) $(CFLAGS) $(DEBUG) list.cpp -o list.o
test_add.o:	test_add.cpp
	$(CC) $(CFLAGS) $(DEBUG) test_add.cpp -o test_add.o
poortool.o:	poortool.c
	$(CC) $(CFLAGS) $(DEBUG) poortool.c -o poortool.o

splint-me:
	$(CHECK) $(CHECK_FLAGS) .

clean:
	rm -f list.exe
	rm -f list.o
	rm -f main.o
	rm -f test_add.o
	rm -f poortool.o
	rm -f core

#
# Fin
#

