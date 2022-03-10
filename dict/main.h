#ifndef __MAIN_H
#define __MAIN_H

#include "ini.h"
#include "sds.h"
#include "dict.h"


static uint32_t
sdsHashCallBack(const void *key)
{
    return dictGenHashFunction((unsigned char *)key, sdslen((char *)key));
}

static int
sdsCompareCallBack(void *privdata, const void *key1, const void *key2)
{
    int		l1, l2;

    (void)privdata;
    l1 = sdslen((sds)key1);
    l2 = sdslen((sds)key2);
    if (l1 != l2) return 0;
    return memcmp(key1, key2, l1) == 0;
}

static void *
sdsDupCallBack(void *privdata, const void *key)
{
    return sdsdup((sds)key);
}

static void
sdsFreeCallBack(void *privdata, void *val)
{
    (void)privdata;
    sdsfree(val);
}

dictType sdsDictCallBacks = {
    .hashFunction	= sdsHashCallBack,
    .keyCompare		= sdsCompareCallBack,
    .keyDup		= sdsDupCallBack,
    .keyDestructor	= sdsFreeCallBack,
    .valDestructor	= sdsFreeCallBack,
};

#endif
