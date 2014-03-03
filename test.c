#include <stdio.h>
#include "sqlite3.h" 

#define DEBUG
#ifdef  DEBUG
  #define LOGD(fmt, ...) printf(fmt, ##__VA_ARGS__)
#else
  #define LOGD(fmt, ...)
#endif /* DEBUG */ 

int main(int argc, char* argv[])
{
    sqlite3 *db;
    
    if (SQLITE_OK != sqlite3_open_v2(":memory:", &db, SQLITE_OPEN_READWRITE, NULL)) {
        LOGD("%s", sqlite3_errmsg(db));
        return 1;
    }
    LOGD("success\n");

    sqlite3_close(db);
    return 0;
}
