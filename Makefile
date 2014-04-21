DIR_BASE = $(HOME)/research/composite/src
DIR_TEST = $(DIR_BASE)/components/implementation/tests/
DIR_LIB = $(DIR_BASE)/components/lib/
DIR_RUNSCRIPT = $(DIR_BASE)/platform/linux/util

.PHONY: init

init:
	cp -r ./libsqlite/ $(DIR_LIB)
	cp -r ./unit_sqlite/ $(DIR_TEST)
	cp unit_sqlite.sh $(DIR_RUNSCRIPT)
