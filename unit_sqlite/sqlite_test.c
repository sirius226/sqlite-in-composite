#include <cos_component.h>
#include <torrent.h>

#include <cbuf.h>
#include <print.h>
#include <cos_synchronization.h>
#include <evt.h>
#include <cos_alloc.h>
#include <cos_map.h>
#include <fs.h>
#include "../../../lib/libsqlite/sqlite3.h"


#define DEBUG
#ifdef  DEBUG
  #define LOGD(fmt, ...) printc("[SQLite Test] "fmt"\n", ##__VA_ARGS__)
#else
  #define LOGD(fmt, ...)
#endif /* DEBUG */ 

static void __create_table(sqlite3 *db) {
   char *sql = "CREATE TABLE student("  \
         "id    INTEGER PRIMARY KEY AUTOINCREMENT," \
         "name  TEXT NOT NULL," \
         "age   INTEGER );" ;

   char *errMsg = NULL;
   if (SQLITE_OK != sqlite3_exec(db, sql, NULL, NULL, &errMsg)){
        LOGD("ERR: %s\n", errMsg);
        sqlite3_free(errMsg);
   } else {
        LOGD("Table created successfully.\n");
   }
}

static void __fill_data(sqlite3 *db) {
   char *sql = "INSERT INTO student (name, age) VALUES ('Qing', '26');";
   char *errMsg = NULL;
   if (SQLITE_OK != sqlite3_exec(db, sql, NULL, NULL, &errMsg)){
        LOGD("ERR: %s\n", errMsg);
        sqlite3_free(errMsg);
   } else {
        LOGD("Data inserted successfully.\n");
   }
}

void cos_init(void)
{
    LOGD("BEGIN");

    td_t t1, t2;
    long evt1;
    char *params1 = "unused";

    evt1 = evt_split(cos_spd_id(), 0, 0);
    assert(evt1 > 0);

    t1 = tsplit(cos_spd_id(), td_root, params1, strlen(params1), TOR_ALL, evt1);
    if (t1 < 0) {
        LOGD("FAILED: split");
        return;
    }
    
    trelease(cos_spd_id(), t1);
    LOGD("PASSED: split->release");
}

