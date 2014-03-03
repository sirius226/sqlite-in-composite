SQLITE-LIB=sqlite3-for-composite

all: $(SQLITE-LIB).a test.c
	cc -o test test.c -l$(SQLITE-LIB) -L. -lpthread -ldl

$(SQLITE-LIB).o:
	cc -c -o $(SQLITE-LIB).o src/sqlite3.c 

$(SQLITE-LIB).a: $(SQLITE-LIB).o
	ar rcs lib$(SQLITE-LIB).a $(SQLITE-LIB).o
	
clean:
	rm lib$(SQLITE-LIB).a $(SQLITE-LIB).o test

	
