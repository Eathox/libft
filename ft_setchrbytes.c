/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_setchrbytes.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/27 01:29:23 by pholster       #+#    #+#                */
/*   Updated: 2019/03/27 01:29:23 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_setchrbytes(long long *bytes, char *str)
{
	size_t	i;

	i = 0;
	if (bytes == NULL || str == NULL)
		return ;
	ft_memset(&bytes[0], 0, sizeof(bytes[0]));
	ft_memset(&bytes[1], 0, sizeof(bytes[1]));
	while (str[i] != '\0')
	{
		if (str[i] >= 64)
			bytes[1] |= ((long long)1 << (str[i] - 64));
		else
			bytes[0] |= ((long long)1 << str[i]);
		i++;
	}
}
