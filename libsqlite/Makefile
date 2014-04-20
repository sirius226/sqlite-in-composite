SQLITE = sqlite
LIBSQLITE = lib$(SQLITE).a
OS = os-composite

.PHONY: all
all: $(LIBSQLITE)

$(SQLITE).o: sqlite3.h
	cc -fno-stack-protector -DSQLITE_THREADSAFE=0 -DSQLITE_OMIT_LOAD_EXTENSION -DSQLITE_OMIT_LOCALTIME -DSQLITE_OS_OTHER=1 -c -o $(SQLITE).o sqlite3.c -Iinclude

$(OS).o: os-composite.c
	cc -c -o $(OS).o os-composite.c -Iinclude

$(LIBSQLITE): $(SQLITE).o $(OS).o
	ar rcs $(LIBSQLITE) $(SQLITE).o $(OS).o
	
.PHONY: clean
clean:
	rm $(LIBSQLITE) $(SQLITE).o $(OS).o test

	
