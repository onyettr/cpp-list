#*******************************************************************************
# File name        : makeile
# File description : C++ Single Link list builda
# Author           : ronyett
#*******************************************************************************

SRC_DIR		= 	.
OBJECT_DIR	= 	$(SRC_DIR)/object
MAKE_DIR_CMD	= 	mkdir $(OBJECT_DIR)

CC		=	g++
LINK  		=	g++
AR		=	ar
ARFLAGS		=       rcs
CFLAGS		=	-g -c -Wall -pedantic
#CFLAGS		+= 	-DDEBUG_TRACE
LFLAGS		=

MAKE            = 	gmake
CHECK		= 	cppcheck
CHECK_FLAGS	= 	--language=c++ --enable=all -igoogletest

# -DDEBUG_TRACE	Will turn on deep trace per function
# -DEXCEPTION	Will use the real exceptions with the 'try' that's in the test harness

# Build objects
OBJS  = $(OBJECT_DIR)/main.o 	 	\
	$(OBJECT_DIR)/poortool.o

LIST_OBJS = 				\
	$(OBJECT_DIR)/list.o

TEST_OBJS = 				\
	$(OBJECT_DIR)/test_add.o 	\
	$(OBJECT_DIR)/test_del.o 	\
	$(OBJECT_DIR)/test_rev.o 	\
	$(OBJECT_DIR)/test_size.o	\
	$(OBJECT_DIR)/test_copy.o	\
	$(OBJECT_DIR)/test_back.o	\
	$(OBJECT_DIR)/test_front.o	\
	$(OBJECT_DIR)/test_search.o	\
	$(OBJECT_DIR)/test_del_back.o	\
	$(OBJECT_DIR)/test_del_front.o	\
	$(OBJECT_DIR)/test_empty.o

LISTLIB = liblist.a

TESTLIB = libtest.a

LIBS  	= $(TESTLIB) $(LISTLIB)

#*******************************************************************************
# Build targets:
# all	Creates object directory, builds executable and runs checker
# lib	Build only the list library, no test harness
#*******************************************************************************
all:	$(OBJECT_DIR) list.exe splint-me gtest

lib:	$(LIBS)

splint-me:
	$(CHECK) $(CHECK_FLAGS) .

gtest:
	$(MAKE) -f makefile.gtest

$(OBJECT_DIR):
	-$(MAKE_DIR_CMD)

list.exe:	$(OBJS) $(LIBS)
	$(LINK) $(LFLAGS) $(OBJS) -L. -ltest -llist -o list.exe

$(OBJECT_DIR)/main.o:		main.cpp
	$(CC) $(CFLAGS) $(DEBUG) main.cpp -o $(OBJECT_DIR)/main.o

libtest.a:	$(TEST_OBJS)
	$(AR) $(ARFLAGS) libtest.a $(TEST_OBJS)

liblist.a:	$(OBJECT_DIR)/list.o
	$(AR) $(ARFLAGS) liblist.a $(OBJECT_DIR)/list.o 

$(OBJECT_DIR)/list.o:	list.cpp list.h
	$(CC) $(CFLAGS) $(DEBUG) list.cpp -o $(OBJECT_DIR)/list.o

$(OBJECT_DIR)/test_add.o:	test_add.cpp
	$(CC) $(CFLAGS) $(DEBUG) test_add.cpp -o $(OBJECT_DIR)/test_add.o

$(OBJECT_DIR)/test_del.o:	test_del.cpp
	$(CC) $(CFLAGS) $(DEBUG) test_del.cpp -o $(OBJECT_DIR)/test_del.o

$(OBJECT_DIR)/test_rev.o:	test_rev.cpp
	$(CC) $(CFLAGS) $(DEBUG) test_rev.cpp -o $(OBJECT_DIR)/test_rev.o

$(OBJECT_DIR)/test_del_back.o:	test_del_back.cpp
	$(CC) $(CFLAGS) $(DEBUG) test_del_back.cpp -o $(OBJECT_DIR)/test_del_back.o

$(OBJECT_DIR)/test_del_front.o:	test_del_front.cpp
	$(CC) $(CFLAGS) $(DEBUG) test_del_front.cpp -o $(OBJECT_DIR)/test_del_front.o

$(OBJECT_DIR)/test_size.o:	test_size.cpp
	$(CC) $(CFLAGS) $(DEBUG) test_size.cpp -o $(OBJECT_DIR)/test_size.o

$(OBJECT_DIR)/test_copy.o:	test_copy.cpp
	$(CC) $(CFLAGS) $(DEBUG) test_copy.cpp -o $(OBJECT_DIR)/test_copy.o

$(OBJECT_DIR)/test_back.o:	test_back.cpp
	$(CC) $(CFLAGS) $(DEBUG) test_back.cpp -o $(OBJECT_DIR)/test_back.o

$(OBJECT_DIR)/test_front.o:	test_front.cpp
	$(CC) $(CFLAGS) $(DEBUG) test_front.cpp -o $(OBJECT_DIR)/test_front.o

$(OBJECT_DIR)/test_search.o:	test_search.cpp
	$(CC) $(CFLAGS) $(DEBUG) test_search.cpp -o $(OBJECT_DIR)/test_search.o

$(OBJECT_DIR)/test_empty.o:	test_empty.cpp
	$(CC) $(CFLAGS) $(DEBUG) test_empty.cpp -o $(OBJECT_DIR)/test_empty.o

$(OBJECT_DIR)/poortool.o:	poortool.c
	$(CC) $(CFLAGS) $(DEBUG) poortool.c -o $(OBJECT_DIR)/poortool.o

clean:
	rm -f list.exe
	rm -f $(OBJECT_DIR)/list.o
	rm -f liblist.a
	rm -f libtest.a
	rm -f $(OBJECT_DIR)/main.o
	rm -f $(OBJECT_DIR)/test_add.o
	rm -f $(OBJECT_DIR)/test_del.o
	rm -f $(OBJECT_DIR)/test_rev.o
	rm -f $(OBJECT_DIR)/test_size.o
	rm -f $(OBJECT_DIR)/test_back.o
	rm -f $(OBJECT_DIR)/test_copy.o
	rm -f $(OBJECT_DIR)/test_front.o
	rm -f $(OBJECT_DIR)/test_empty.o
	rm -f $(OBJECT_DIR)/test_search.o
	rm -f $(OBJECT_DIR)/test_del_back.o
	rm -f $(OBJECT_DIR)/test_del_front.o
	rm -f $(OBJECT_DIR)/poortool.o
	rm -f core

#
# Fin
#

