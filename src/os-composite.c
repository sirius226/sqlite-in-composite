#include "sqlite3.h"

#ifndef MAX_PATHNAME
#define MAX_PATHNAME 512
#endif

static int compositeRandomness(sqlite3_vfs *NotUsed, int nBuf, char *zBuf) {
    return nBuf;
}

int sqlite3_os_init(void)
{
    static sqlite3_vfs composite_vfs = {
        3,                            /* iVersion */
        0,                            /* szOsFile */
        MAX_PATHNAME,                 /* mxPathname */
        0,                            /* pNext */
        "composite",                  /* zName */
        0,                            /* pAppData */
        0,                     /* xOpen */
        0,                   /* xDelete */
        0,                   /* xAccess */
        0,             /* xFullPathname */
        0,                            /* xDlOpen */
        0,                            /* xDlError */
        0,                            /* xDlSym */
        0,                            /* xDlClose */
        compositeRandomness,          /* xRandomness */
        0,                    /* xSleep */
        0,              /* xCurrentTime */
        0,                            /* xGetLastError */
        0,                            /* xCurrentTimeInt64 */
        0,                            /* xSetSystemCall */
        0,                            /* xGetSystemCall */
        0,                            /* xNextSystemCall */
    };

    sqlite3_vfs_register(&composite_vfs, 1);
    return SQLITE_OK; 
}

int sqlite3_os_end(void)
{
    return SQLITE_OK;
}
