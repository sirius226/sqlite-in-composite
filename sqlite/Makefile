C_OBJS=sqlite.o
ASM_OBJS=
COMPONENT=sql.o
INTERFACES=torrent
DEPENDENCIES=printc cbufp cbuf_c evt lock mem_mgr_large valloc
IF_LIB=./libsqlite.a $(DIETDIR)/bin-i386/libm.a

pre: first all
first:
	@cp $(SQLITEOBJ) .

include ../../Makefile.subsubdir

