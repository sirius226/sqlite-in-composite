SQLITE = sqlite3-for-composite
LIBSQLITE = lib$(SQLITE).a

test: $(LIBSQLITE) test.c
	cc -o test test.c -l$(SQLITE) -L.

$(SQLITE).o: src/sqlite3.h
	cc -DSQLITE_THREADSAFE=0 -DSQLITE_OMIT_LOAD_EXTENSION -c -o $(SQLITE).o src/sqlite3.c

$(LIBSQLITE): $(SQLITE).o
	ar rcs $(LIBSQLITE) $(SQLITE).o
	
.PHONY: clean
clean:
	rm $(LIBSQLITE) $(SQLITE).o test

	
