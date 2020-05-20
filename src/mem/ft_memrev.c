/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memrev.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 10:18:13 by pholster      #+#    #+#                 */
/*   Updated: 2019/08/21 20:43:11 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft/types.h"

#include "mem.h"

#define UNROLLED_2_COUNT 4
#define UNROLLED_8_COUNT 4

static void		swap_2(
	t_uint8 *stream,
	size_t len,
	size_t i
)
{
	t_uint8	temp;

	temp = stream[i];
	stream[i] = stream[(len - 1) - i];
	stream[(len - 1) - i] = temp;
}

static size_t	swap_8(
	t_uint8 *stream,
	size_t len,
	size_t i
)
{
	swap_2(stream, len, i + 0);
	swap_2(stream, len, i + 1);
	swap_2(stream, len, i + 2);
	swap_2(stream, len, i + 3);
	return (UNROLLED_2_COUNT);
}

static size_t	swap_32(
	t_uint8 *stream,
	size_t len
)
{
	size_t			i;
	size_t const	step = (UNROLLED_8_COUNT * 8) / 2;

	i = 0;
	while ((i + step) <= (len / 2))
	{
		i += swap_8(stream, len, i);
		i += swap_8(stream, len, i);
		i += swap_8(stream, len, i);
		i += swap_8(stream, len, i);
	}
	return (i);
}

void			*ft_memrev(
	void *mem,
	size_t len
)
{
	size_t	i;
	t_uint8	*stream;

	i = 0;
	stream = mem;
	if (len >= 32)
		i = swap_32(mem, len);
	while (i < (len / 2))
	{
		swap_2(stream, len, i);
		i++;
	}
	return (mem);
}
