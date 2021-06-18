/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/15 20:17:24 by pholster      #+#    #+#                 */
/*   Updated: 2019/08/21 21:12:24 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

#include "../types/types.h"
#include "mem.h"

/*
** * Searches len amount of bytes in mem for the last instance of c
** * Returns NULL if no instacne of c was found
*/
void		*ft_memrchr(
	void const *mem,
	t_uint8 c,
	size_t len
) {
	size_t			i;
	t_uint8 const	*mem_byte;

	i = len;
	mem_byte = mem;
	while (i > 0)
	{
		i--;
		if (mem_byte[i] == c)
			return ((void *)(mem_byte + i));
	}
	return (NULL);
}
