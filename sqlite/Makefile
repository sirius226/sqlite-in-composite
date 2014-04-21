C_OBJS=sqlite.o
ASM_OBJS=
COMPONENT=sql.o
INTERFACES=torrent
DEPENDENCIES=printc cbufp cbuf_c evt lock mem_mgr_large valloc
IF_LIB=./libsqlite.a

pre: first all
first:
	@cp $(SQLITEOBJ) .

include ../../Makefile.subsubdir

