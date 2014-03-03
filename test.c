#include <stdio.h>
#include "sqlite3.h" 

#define DEBUG
#ifdef  DEBUG
  #define LOGD(fmt, ...) printf(fmt, ##__VA_ARGS__)
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

int main(int argc, char* argv[])
{
    sqlite3 *db;
    
    if (SQLITE_OK != sqlite3_open_v2(":memory:", &db, SQLITE_OPEN_READWRITE, NULL)) {
        LOGD("ERR: %s\n", sqlite3_errmsg(db));
        return 1;
    }
    LOGD("Datebase connected.\n");

    __create_table(db);
    __fill_data(db);
    sqlite3_close(db);
    LOGD("Database closed.\n");
    return 0;
}
