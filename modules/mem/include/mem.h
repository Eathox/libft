#pragma once

#include <sys/types.h>

#include "types/include/types.h"

void *ft_calloc(
	size_t count,
	size_t size
);

void *ft_memalloc(
	size_t size
);

void ft_arraydel(
	void ***array,
	void (*del)(void**)
);

void ft_memdel(
	void **adr
);

void *ft_bzero(
	void *mem,
	size_t len
);

void *ft_memset(
	void *mem,
	uint8_t c,
	size_t len
);

void *ft_memset4(
	void *mem,
	uint32_t c,
	size_t len
);

void *ft_memrev(
	void *mem,
	size_t len
);

void *ft_memchr(
	void const *mem,
	uint8_t c,
	size_t len
);

void *ft_memrchr(
	void const *mem,
	uint8_t c,
	size_t len
);

void *ft_memmem(
	void const *mem,
	size_t mem_len,
	void const *needle,
	size_t needle_len
);

int ft_memcmp(
	void const *mem1,
	void const *mem2,
	size_t len
);

void *ft_memcpy(
	void *dst,
	void const *src,
	size_t len
);

void *ft_memccpy(
	void *dst,
	void const *src,
	uint8_t c,
	size_t len
);

void *ft_memrcpy(
	void *dst,
	void const *src,
	size_t len
);

void *ft_memmove(
	void *dst,
	void const *src,
	size_t len
);

void *ft_memdup(
	void const *mem,
	size_t len
);
