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

}
