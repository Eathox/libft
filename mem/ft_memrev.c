/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memrev.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 10:18:13 by pholster       #+#    #+#                */
/*   Updated: 2019/08/21 20:43:11 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft/types.h"

#include "mem.h"

void	ft_memrev(void *str, size_t size)
{
	size_t	i;
	t_uint8	temp;
	t_uint8	*stream;

	i = 0;
	stream = str;
	while (i < (size / 2))
	{
		temp = stream[i];
		stream[i] = stream[(size - 1) - i];
		stream[(size - 1) - i] = temp;
		i++;
	}
}
