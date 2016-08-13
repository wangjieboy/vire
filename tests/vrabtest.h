#ifndef _VRABTEST_H_
#define _VRABTEST_H_

#include <darray.h>

struct redisContext;
struct redisAsyncContext;

typedef struct conn_context {
    struct redisContext *ctx;
    struct redisAsyncContext *actx;    
} conn_context;

typedef struct abtest_server {
    sds host;
    int port;

    darray *conn_contexts;  /* connection context */

    void *data;
} abtest_server;

typedef struct abtest_group {
    int type;
    
    darray abtest_servers;    /* type: abtest_server */
    
} abtest_group;

extern int expire_enabled;

darray *abtest_groups_create(char *groups_string);
void abtest_groups_destroy(darray *abgs);

#endif
