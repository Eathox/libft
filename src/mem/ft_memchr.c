/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/15 20:17:24 by pholster      #+#    #+#                 */
/*   Updated: 2019/08/21 21:12:24 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

#include "ft/types.h"
#include "mem.h"

/*
** * Searchs len amount of bytes in mem for the first instance of c
*/
void		*ft_memchr(
	void const *mem,
	t_uint8 c,
	size_t len
)
{
	size_t			i;
	t_uint8 const	*mem_byte;

	i = 0;
	mem_byte = mem;
	while (i < len)
	{
		if (mem_byte[i] == c)
			return ((void *)(mem_byte + i));
		i++;
	}
	return (NULL);
}
