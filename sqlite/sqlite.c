#include <cos_component.h>
#include <torrent.h>
#include <torlib.h>

#include <cbuf.h>
#include <print.h>
#include <cos_synchronization.h>
#include <evt.h>
#include <cos_alloc.h>
#include <cos_map.h>
#include <fs.h>

#include "../../../lib/libsqlite/sqlite3.h"

static cos_lock_t fs_lock;
struct fsobj root;
#define LOCK() if (lock_take(&fs_lock)) BUG();
#define UNLOCK() if (lock_release(&fs_lock)) BUG();

#define DEBUG
#ifdef  DEBUG
  #define LOGD(fmt, ...) printc("[SQLite Torrent] "fmt"\n", ##__VA_ARGS__)
#else
  #define LOGD(fmt, ...)
#endif /* DEBUG */ 

#define ARRAY_SIZE(a) (sizeof(a)/sizeof(a[0]))

static sqlite3 *g_handler[16];
static int g_empty_idx;

td_t tsplit(spdid_t spdid, td_t td, char *param, int len, tor_flags_t tflags, long evtid) 
{
    if (g_empty_idx < 0 || g_empty_idx > (int)ARRAY_SIZE(g_handler)) {
        LOGD("ERR: Out of Capacity");
        return -1;
    }

    sqlite3 *db;
    
    if (SQLITE_OK != sqlite3_open_v2(":memory:", &db, SQLITE_OPEN_READWRITE, NULL)) {
        LOGD("ERR: %s\n", sqlite3_errmsg(db));
        return -1;
    }
    LOGD("Datebase connected.");

    td_t rtd = g_empty_idx;
    g_empty_idx = (int)g_handler[rtd];
    g_handler[rtd] = db;
    return rtd;
}

int tmerge(spdid_t spdid, td_t td, td_t td_into, char *param, int len)
{
	int ret = 0;
	return ret;
}

void trelease(spdid_t spdid, td_t td)
{
    sqlite3 *db = g_handler[td];
    sqlite3_close(db);
    g_handler[td] = (void *)g_empty_idx;
    g_empty_idx = td;
    LOGD("Database closed.");
}

int tread(spdid_t spdid, td_t td, int cbid, int sz)
{
	int ret = -1;
	return ret;
}

int twrite(spdid_t spdid, td_t td, int cbid, int sz)
{
    LOGD("twrite invoked");
    char *buf;
    char *errMsg = NULL;
    int ret = 0;
    buf = cbuf2buf(cbid, sz);
    LOGD("buf: %s", buf);
    sqlite3 *db = g_handler[td];
    LOGD("db: %p", db);

    if (0) {
    //if (SQLITE_OK != sqlite3_exec(db, buf, NULL, NULL, &errMsg)){
        LOGD("ERR: %s\n", errMsg);
        sqlite3_free(errMsg);
	    ret = -1;
    } else {
        LOGD("Table created successfully.\n");
        ret = 0;
    }
    return ret;
}

int cos_init(void)
{
    LOGD("Component Init.");
    int i = 0;
    for (i = 0; i < (int)ARRAY_SIZE(g_handler); ++i) {
        g_handler[i] = (void *)(i + 1); /* Initialize handler array */
    }
    g_empty_idx = 0;
    return 0;
}
