#ifndef FT_PRIV_H
#define FT_PRIV_H

#include <stdlib.h>

typedef struct s_gnl {
    int fd;
    char *str;
    size_t len;
    struct s_gnl *next;
} t_gnl;

#endif
