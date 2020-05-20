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

#define UNROLLED_8_COUNT 4

static size_t	set_32(
	t_uint64 *stream_8,
	t_uint8 c,
	size_t len
)
{
	t_uint64		c_8;
	size_t			i;
	size_t const	step = UNROLLED_8_COUNT;
	size_t const	c_fit = sizeof(c_8) / sizeof(c);
	size_t const	len_8 = len / c_fit;

	c_8 = c;
	c_8 |= c_8 << 010;
	c_8 |= c_8 << 020;
	c_8 |= c_8 << 040;
	i = 0;
	while ((i + step) <= len_8)
	{
		stream_8[i + 0] = c_8;
		stream_8[i + 1] = c_8;
		stream_8[i + 2] = c_8;
		stream_8[i + 3] = c_8;
		i += step;
	}
	return (i * c_fit);
}

/*
** * Sets len amount of bytes in mem to the value of c
** * Returns mem
*/
void			*ft_memset(
	void *mem,
	t_uint8 c,
	size_t len
)
{
	size_t		i;
	t_uint8		*stream;

	i = 0;
	stream = mem;
	if (len >= 32)
		i = set_32(mem, c, len);
	while (i < len)
	{
		stream[i] = c;
		i++;
	}
	return (mem);
}
