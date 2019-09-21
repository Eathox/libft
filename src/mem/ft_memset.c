/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 16:08:38 by pholster       #+#    #+#                */
/*   Updated: 2019/08/21 21:13:07 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mem.h"

static unsigned long long	prepare_8(unsigned long long c)
{
	unsigned long long	temp_c;

	temp_c = (c << 0);
	temp_c |= (c << 8);
	temp_c |= (c << 16);
	temp_c |= (c << 24);
	temp_c |= (c << 32);
	temp_c |= (c << 40);
	temp_c |= (c << 48);
	temp_c |= (c << 56);
	return (temp_c);
}

static void			set_32(unsigned long long *str_8, unsigned long long c_8,
						size_t *i, const size_t len)
{
	size_t			index_step;
	const size_t	step = 4;
	const size_t	len_8 = len / (2 * step);

	index_step = 0;
	while ((index_step + step) < len_8)
	{
		str_8[index_step] = c_8;
		str_8[index_step + 1] = c_8;
		str_8[index_step + 2] = c_8;
		str_8[index_step + 3] = c_8;
		index_step += step;
	}
	*i = index_step * (2 * step);
}

void				*ft_memset(void *str, int c, size_t len)
{
	size_t				i;
	unsigned char		temp_c;
	unsigned char		*temp_str;

	temp_c = c;
	set_32(str, prepare_8(temp_c), &i, len);
	temp_str = str;
	while (i < len)
	{
		temp_str[i] = temp_c;
		i++;
	}
	return (str);
}
