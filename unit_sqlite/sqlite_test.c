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

//static void __fill_data(sqlite3 *db) {
//   char *sql = "INSERT INTO student (name, age) VALUES ('Qing', '26');";
//   char *errMsg = NULL;
//   if (SQLITE_OK != sqlite3_exec(db, sql, NULL, NULL, &errMsg)){
//        LOGD("ERR: %s\n", errMsg);
//        sqlite3_free(errMsg);
//   } else {
//        LOGD("Data inserted successfully.\n");
//   }
//}

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
        LOGD("FAILED: split");
        return;
    }

    trelease(cos_spd_id(), t1);
    LOGD("PASSED: split->release");

    sql = "CREATE TABLE student("  \
         "id    INTEGER PRIMARY KEY AUTOINCREMENT," \
         "name  TEXT NOT NULL," \
         "age   INTEGER );" ;
    t1 = tsplit(cos_spd_id(), td_root, params1, strlen(params1), TOR_ALL, evt1);
    ret = twrite_pack(cos_spd_id(), t1, sql, 1024);
    LOGD("%s: Create table.", ret < 0 ? "FAILED" : "PASSED");
    //trelease(cos_spd_id(), t1);
}

