/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmem.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/26 13:54:38 by pholster      #+#    #+#                 */
/*   Updated: 2020/05/26 13:54:38 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

#include "mem.h"

/*
** * Searches len amount of bytes in mem for the first instance of needle
** * Returns mem if needle_len is 0 and NULL if no instance of needle was found
*/
void		*ft_memmem(
	void const *mem,
	size_t mem_len,
	void const *needle,
	size_t needle_len
) {
	t_uint8 const	*mem_byte = mem;
	t_uint8 const	*needle_byte = needle;
	size_t			i;

	i = 0;
	if (needle_len == 0)
		return ((void *)mem_byte);
	while (i < mem_len) {
		if ((mem_len - i) < needle_len)
			return (NULL);
		if (mem_byte[i] == needle_byte[0]) {
			if (ft_memcmp(mem_byte + i, needle_byte, needle_len) == 0)
				return ((void *)(mem_byte + i));
		}
		i++;
	}
	return (NULL);
}
