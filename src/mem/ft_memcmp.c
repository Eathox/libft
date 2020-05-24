/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 17:53:02 by pholster      #+#    #+#                 */
/*   Updated: 2019/08/21 21:12:28 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft/types.h"

#include "mem.h"

/*
** * Compares len bytes of mem1 to mem2
** * Returns diffrance between first not equal byte or 0 if equal
*/
int			ft_memcmp(
	void const *mem1,
	void const *mem2,
	size_t len
)
{
	size_t			i;
	t_uint8 const	*mem1_byte;
	t_uint8 const	*mem2_byte;

	i = 0;
	mem1_byte = mem1;
	mem2_byte = mem2;
	while (i < len)
	{
		if (mem1_byte[i] != mem2_byte[i])
			return (mem1_byte[i] - mem2_byte[i]);
		i++;
	}
	return (0);
}
