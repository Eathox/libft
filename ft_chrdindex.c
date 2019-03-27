/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_chrdindex.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/03 22:38:37 by pholster       #+#    #+#                */
/*   Updated: 2019/03/27 01:12:50 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_chrdindex(const char *str, const char *dlm)
{
	size_t		i;
	long long	chars[2];

	i = 0;
	ft_memset(chars, 0, sizeof(chars));
	while (dlm[i] != '\0')
	{
		if (dlm[i] >= 64)
			chars[1] |= ((long long)1 << (dlm[i] - 64));
		else
			chars[0] |= ((long long)1 << dlm[i]);
		i++;
	}
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 64 && chars[1] & ((long long)1 << (str[i] - 64)))
			return (i);
		if (chars[0] & ((long long)1 << str[i]))
			return (i);
		i++;
	}
	return (-1);
}
