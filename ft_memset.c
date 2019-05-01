/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 16:08:38 by pholster       #+#    #+#                */
/*   Updated: 2019/05/01 02:59:44 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memset(void *str, int c, size_t len)
{
	size_t			i;
	long long		temp_c;
	char			*temp_str;

	i = 0;
	temp_c = 0;
	temp_str = str;
	while (i < 8)
	{
		temp_c |= (((long long)(unsigned char)c) << (i * 8));
		i++;
	}
	i = 0;
	while (len - (i * 8) >= 8)
	{
		((long long *)temp_str)[i] = temp_c;
		i++;
	}
	i *= 8;
	while (i < len)
	{
		temp_str[i] = (unsigned char)c;
		i++;
	}
	return (str);
}
