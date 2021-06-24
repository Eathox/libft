/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 16:08:38 by pholster      #+#    #+#                 */
/*   Updated: 2019/08/21 21:13:07 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "mem.h"

static uint64_t prep_c_8(
	uint8_t c
) {
	uint64_t c_8 = c;
	c_8 |= c_8 << 010;
	c_8 |= c_8 << 020;
	c_8 |= c_8 << 040;
	return (c_8);
}

static size_t set_8(
	uint64_t *mem_byte_8,
	uint8_t c,
	size_t len
) {
	uint64_t const c_8 = prep_c_8(c);
	size_t const c_fit = sizeof(c_8) / sizeof(c);
	size_t const len_8 = len / c_fit;

	size_t i = 0;
	while (i < len_8) {
		mem_byte_8[i] = c_8;
		i++;
	}
	return (i * c_fit);
}

/*
** * Sets len amount of bytes in mem to the value of c
** * Returns mem
*/
void *ft_memset(
	void *mem,
	uint8_t c,
	size_t len
) {
	uint8_t *mem_byte = mem;

	size_t i = 0;
	while (i < len && ((size_t)(mem_byte + i) & 7) != 0) {
		mem_byte[i] = c;
		i++;
	}
	i += set_8((uint64_t*)(mem_byte + i), c, len - i);

	while (i < len) {
		mem_byte[i] = c;
		i++;
	}
	return (mem);
}
