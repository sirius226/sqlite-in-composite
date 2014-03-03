#include <stdio.h>
#include "sqlite3.h" 

#define DEBUG
#ifdef  DEBUG
  #define LOGD(fmt, ...) printf(fmt, ##__VA_ARGS__)
#else
  #define LOGD(fmt, ...)
#endif /* DEBUG */ 

static void __create_table(sqlite3 *db) {
   char *sql = "CREATE TABLE company("  \
         "id INT PRIMARY KEY     NOT NULL," \
         "name           TEXT    NOT NULL," \
         "age            INT);" ;

   char *errMsg = NULL;
   if (SQLITE_OK != sqlite3_exec(db, sql, NULL, NULL, &errMsg)){
        LOGD("SQL error: %s\n", errMsg);
        sqlite3_free(errMsg);
   } else {
        LOGD("Table created successfully.\n");
   }
}

int main(int argc, char* argv[])
{
    sqlite3 *db;
    
    if (SQLITE_OK != sqlite3_open_v2(":memory:", &db, SQLITE_OPEN_READWRITE, NULL)) {
        LOGD("%s\n", sqlite3_errmsg(db));
        return 1;
    }
    LOGD("Datebase connected.\n");

    __create_table(db);
    sqlite3_close(db);
    LOGD("Database closed.\n");
    return 0;
}
