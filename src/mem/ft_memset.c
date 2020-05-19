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

static size_t	set_32(
	t_uint64 *stream_8,
	t_uint8 c,
	size_t len
)
{
	t_uint64		c_8;
	size_t			index_step;
	size_t const	step = 4;
	size_t const	len_8 = len / sizeof(c_8);

	c_8 = c;
	index_step = 0;
	c_8 |= c_8 << 010;
	c_8 |= c_8 << 020;
	c_8 |= c_8 << 040;
	while ((index_step + step) < len_8)
	{
		stream_8[index_step + 0] = c_8;
		stream_8[index_step + 1] = c_8;
		stream_8[index_step + 2] = c_8;
		stream_8[index_step + 3] = c_8;
		index_step += step;
	}
	return (index_step * sizeof(c_8));
}

/*
** * Sets len amount of bytes to the value of c in the memory mem
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
