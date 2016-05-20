OBJS = teststring.o mystrupdown.o mystrinv.o mystrchrn.o mystrncpy.o mystrncat.o mystrlen.o
CC = gcc

teststring : $(OBJS)
	$(CC) -o $@ $(OBJS)

teststring.o : teststring.c mystrupdown.h mystrinv.h mystrchrn.h mystrncpy.h mystrncat.h mystrlen.h
	$(CC) -c teststring.c
mystrupdown.o : mystrupdown.c mystrupdown.h
	$(CC) -c mystrupdown.c
mystrinv.o : mystrinv.c mystrinv.h
	$(CC) -c mystrinv.c
mystrchrn.o : mystrchrn.c mystrchrn.h
	$(CC) -c mystrchrn.c
mystrncpy.o : mystrncpy.c mystrncpy.h
	$(CC) -c mystrncpy.c
mystrncat.o : mystrncat.c mystrncat.h
	$(CC) -c mystrncat.c
mystrlen.o : mystrlen.c mystrlen.h
	$(CC) -c mystrlen.c
clean :
	rm -f teststring $(OBJS)