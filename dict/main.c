/*
 * https://github.com/benhoyt/inih
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

typedef struct
{
    int version;
    const char* name;
    const char* email;
    const char* active;
} configuration;

static int handler(void* user, const char* section, const char* name,
                   const char* value)
{
    configuration* pconfig = (configuration*)user;

    #define MATCH(s, n) strcmp(section, s) == 0 && strcmp(name, n) == 0
    if (MATCH("protocol", "version")) {
        pconfig->version = atoi(value);
    } else if (MATCH("user", "name")) {
        pconfig->name = strdup(value);
    } else if (MATCH("user", "email")) {
        pconfig->email = strdup(value);
    } else if (MATCH("user", "active")) {
        pconfig->active = strdup(value);
    } else {
        return 0;  /* unknown section/name, error */
    }
    return 1;
}


int main() {

    /* ------------------------------ dict ------dictionary------------------*/
	dictEntry *entry;
	int key_i = 0;
    int value_i = 0;
	dict *myHash;


    myHash = dictCreate(&sdsDictCallBacks, NULL);

    dictAdd(myHash, &key_i, &value_i);
    value_i++;
    dictAdd(myHash, &key_i, &value_i);
    value_i++;
    dictAdd(myHash, &key_i, &value_i);
    value_i++;
    dictAdd(myHash, &key_i, &value_i);
    value_i++;
    dictAdd(myHash, &key_i, &value_i);
    value_i++;
    dictAdd(myHash, &key_i, &value_i);

    value_i = 666; // comment this.

    for (int i = 0; i < 10; i++) {
        entry = dictFind(myHash, &i);

        printf("value: %d\n", *((int*)entry->val));
    }

    /* ----------------------------- sds ------ string ----------------------*/

    sds s2;
    sds s3;
    sds s_r;
    sds s_r2;
    char name[100] = "Sohaib";
    char last[] = "Mohamed";

    s3 = sdsnewlen(name, sizeof(name));
    printf("%s\n", s3);

    s_r = sdscatprintf(s3, "%s", "Hello");
    sdstoupper(s_r);
    printf("%s\n", s_r);

    /* ------------------------------ ini ------------ parser ---------------*/

    configuration config;
    config.version = 0;  /* set defaults */
    config.name = NULL;
    config.email = NULL;
    config.active = NULL;

    if (ini_parse("test.ini", handler, &config) < 0) {
        printf("Can't load 'test.ini'\n");
        return 1;
    }
    printf("Config loaded from 'test.ini': version=%d, name=%s, email=%s\n",
            config.version, config.name, config.email);
    printf("Active: %s\n", config.active);

    if (config.name)
        free((void*)config.name);
    if (config.email)
        free((void*)config.email);
    if (config.active)
        free((void*)config.active);


    return 0;
}
