#include "sqlite3.h"

#ifndef MAX_PATHNAME
#define MAX_PATHNAME 512
#endif

/*
** Write nBuf bytes of random data to the supplied buffer zBuf.
*/
static int compositeRandomness(sqlite3_vfs *NotUsed, int nBuf, char *zBuf) 
{
    /* Depends on randomnnes mechanism provided by Composite.
       Simplely do nothing. */
    return nBuf;
}

static int compositeClose(sqlite3_file *pFile)
{
    return 0;
}

static int compositeWrite(sqlite3_file *pFile, const void *zBuf, int iAmt, sqlite_int64 iOfst) {
    return SQLITE_OK;
}

static int compositeOpen(sqlite3_vfs *pVfs, const char *zName, sqlite3_file *pFile, int flags, int *pOutFlags) 
{
    static const sqlite3_io_methods compositeIO = {
        1,                            /* iVersion */
        compositeClose,               /* xClose */
        0,                            /* xRead */
        0,                            /* xWrite */
        0,                            /* xTruncate */
        0,                            /* xSync */
        0,                            /* xFileSize */
        0,                            /* xLock */
        0,                            /* xUnlock */
        0,                            /* xCheckReservedLock */
        0,                            /* xFileControl */
        0,                            /* xSectorSize */
        0                             /* xDeviceCharacteristics */
    };
    pFile->pMethods = &compositeIO;
    return 0;
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
        compositeOpen,                /* xOpen */
        0,                            /* xDelete */
        0,                            /* xAccess */
        0,                            /* xFullPathname */
        0,                            /* xDlOpen */
        0,                            /* xDlError */
        0,                            /* xDlSym */
        0,                            /* xDlClose */
        compositeRandomness,          /* xRandomness */
        0,                            /* xSleep */
        0,                            /* xCurrentTime */
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
