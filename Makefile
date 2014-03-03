SQLITE = sqlite3-for-composite
LIBSQLITE = lib$(SQLITE).a
OS = os-composite

test: $(LIBSQLITE) test.c
	cc -o test test.c -l$(SQLITE) -L. -Iinclude

$(SQLITE).o: include/sqlite3.h
	cc -DSQLITE_THREADSAFE=0 -DSQLITE_OMIT_LOAD_EXTENSION -DSQLITE_OS_OTHER=1 -c -o $(SQLITE).o src/sqlite3.c -Iinclude

$(OS).o: src/os-composite.c
	cc -c -o $(OS).o src/os-composite.c -Iinclude

$(LIBSQLITE): $(SQLITE).o $(OS).o
	ar rcs $(LIBSQLITE) $(SQLITE).o $(OS).o
	
.PHONY: clean
clean:
	rm $(LIBSQLITE) $(SQLITE).o $(OS).o test

	
