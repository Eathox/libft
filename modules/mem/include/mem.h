#pragma once

#include <sys/types.h>

#include "types/include/types.h"

/*
** * Allocates (size * count) amount of memory and sets it all to 0x0
** * Returns NULL if the allocation failed or if the given values would overflow
** * If size, count or both are 0 it also returns NULL
*/
void *ft_calloc(
    size_t count,
    size_t size
);

/*
** * Allocates size amount of memory and sets it all to 0x0
** * Returns NULL if the allocation failed or if size is 0
*/
void *ft_memalloc(
    size_t size
);

/*
** * Frees NULL terminated array and all its members using the function del
** * If the function del is NULL only the array is deleted
*/
void ft_arraydel(
    void ***array,
    void (*del)(void **)
);

/*
** * Frees the memory pointed to by *adr then sets *adr to NULL
** * If adr or *adr are NULL nothing happens
*/
void ft_memdel(
    void **adr
);

/*
** * Sets len amount of bytes in mem to the value 0x0
** * Returns mem
*/
void *ft_bzero(
    void *mem,
    size_t len
);

/*
** * Sets len amount of bytes in mem to the value of c
** * Returns mem
*/
void *ft_memset(
    void *mem,
    uint8_t c,
    size_t len
);

/*
** * Sets len amount of 4 bytes in mem to the value of c
** * Returns mem
*/
void *ft_memset4(
    void *mem,
    uint32_t c,
    size_t len
);

/*
** * Reveseres len amount of bytes in mem
** * Returns mem
*/
void *ft_memrev(
    void *mem,
    size_t len
);

/*
** * Searches len amount of bytes in mem for the first instance of c
** * Returns NULL if no instacne of c was found
*/
void *ft_memchr(
    void const *mem,
    uint8_t c,
    size_t len
);

/*
** * Searches len amount of bytes in mem for the last instance of c
** * Returns NULL if no instacne of c was found
*/
void *ft_memrchr(
    void const *mem,
    uint8_t c,
    size_t len
);

/*
** * Searches len amount of bytes in mem for the first instance of needle
** * Returns mem if needle_len is 0 and NULL if no instance of needle was found
*/
void *ft_memmem(
    void const *mem,
    size_t mem_len,
    void const *needle,
    size_t needle_len
);

/*
** * Compares len bytes of mem1 to mem2
** * Returns diffrance between first not equal byte or 0 if equal
*/
int ft_memcmp(
    void const *mem1,
    void const *mem2,
    size_t len
);

/*
** * Copy len amount of bytes in order of front to back from src to dst
** * This function does not handle memory area overlap use ft_memmove instead
** * Returns dst
*/
void *ft_memcpy(
    void *dst,
    void const *src,
    size_t len
);

/*
** * Copy at most len amount of bytes in order of front to back from src to dst
** * Stoping when c is found in src
** * This function does not handle memory area overlap
** * Returns a pointer to the next byte in dst after c or NULL if c wasent found
*/
void *ft_memccpy(
    void *dst,
    void const *src,
    uint8_t c,
    size_t len
);

/*
** * Copy len amount of bytes in order of back to front from src to dst
** * This function does not handle memory area overlap use ft_memmove instead
** * Returns dst
*/
void *ft_memrcpy(
    void *dst,
    void const *src,
    size_t len
);

/*
** * Copy len amount of bytes from src to dst memory area overlap is handled
** * Returns dst
*/
void *ft_memmove(
    void *dst,
    void const *src,
    size_t len
);

/*
** * Duplicates len amount of bytes from mem
** * Returns NULL if the allocation of the duplicate failed or if len is 0
*/
void *ft_memdup(
    void const *mem,
    size_t len
);
