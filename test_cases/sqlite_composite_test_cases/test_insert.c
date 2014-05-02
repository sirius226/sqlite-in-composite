#include <cos_component.h>
#include <torrent.h>

#include <cbuf.h>
#include <print.h>
#include <cos_synchronization.h>
#include <evt.h>
#include <cos_alloc.h>
#include <cos_map.h>
#include <fs.h>


#define DEBUG
#ifdef  DEBUG
  #define LOGD(fmt, ...) printc("[SQLite Test] "fmt"\n", ##__VA_ARGS__)
#else
  #define LOGD(fmt, ...)
#endif /* DEBUG */

void cos_init(void)
{
    LOGD("BEGIN");

    td_t t1, t2;
    long evt1;
    int ret;
    char *params1 = "unused";
    char *sql = NULL;

    evt1 = evt_split(cos_spd_id(), 0, 0);
    assert(evt1 > 0);


    t1 = tsplit(cos_spd_id(), td_root, params1, strlen(params1), TOR_ALL, evt1);
    if (t1 < 0) {
        LOGD("Can't open database");
        return;
    }

    trelease(cos_spd_id(), t1);
    LOGD("Opened database successfully!");
	 
	sql = "CREATE TABLE COMPANY("  \
         "ID INT PRIMARY KEY     NOT NULL," \
         "NAME           TEXT    NOT NULL," \
         "AGE            INT     NOT NULL," \
         "ADDRESS        CHAR(50)," \
         "SALARY         REAL ;" \
		 "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY) "  \
         "VALUES (1, 'Paul', 32, 'California', 20000.00 ); " \
         "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY) "  \
         "VALUES (2, 'Allen', 25, 'Texas', 15000.00 ); " \
         "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY)" \
         "VALUES (3, 'Teddy', 23, 'Norway', 20000.00 );" \
         "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY)" \
         "VALUES (4, 'Mark', 25, 'Rich-Mond ', 65000.00 );";
		 
    t1 = tsplit(cos_spd_id(), td_root, params1, strlen(params1), TOR_ALL, evt1);
    ret = twrite_pack(cos_spd_id(), t1, sql, 1024);
    LOGD("%s: Records created ", ret < 0 ? "unsuccessfully" : "successfully");
}