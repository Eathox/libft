/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset4.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 16:08:38 by pholster      #+#    #+#                 */
/*   Updated: 2019/08/21 21:13:07 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "mem.h"

/*
** * Sets len amount of 4 bytes in mem to the value of c
** * Returns mem
*/
void			*ft_memset4(
	void *mem,
	t_uint32 c,
	size_t len
)
{
	size_t		i;
	t_uint32	*mem_byte_4;

	i = 0;
	mem_byte_4 = mem;
	while (i < len)
	{
		mem_byte_4[i] = c;
		i++;
	}
	return (mem);
}
