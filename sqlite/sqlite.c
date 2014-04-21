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

#define DEBUG
#ifdef  DEBUG
  #define LOGD(fmt, ...) printc("SQLite: "fmt"\n", ##__VA_ARGS__)
#else
  #define LOGD(fmt, ...)
#endif /* DEBUG */ 

td_t tsplit(spdid_t spdid, td_t td, char *param, int len, tor_flags_t tflags, long evtid) 
{
	td_t ret = -1;
	return ret;
}

int tmerge(spdid_t spdid, td_t td, td_t td_into, char *param, int len)
{
	int ret = 0;
	return ret;
}

void trelease(spdid_t spdid, td_t td)
{
}

int tread(spdid_t spdid, td_t td, int cbid, int sz)
{
	int ret = -1;
	return ret;
}

int twrite(spdid_t spdid, td_t td, int cbid, int sz)
{
	int ret = -1;
	return ret;
}

int cos_init(void)
{
    LOGD("Component Init.");
	return 0;
}
