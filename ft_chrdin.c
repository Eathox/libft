/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_chrdin.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/09 17:42:01 by pholster       #+#    #+#                */
/*   Updated: 2019/03/26 18:40:24 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_chrdin(const char *str, const char *dlm)
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
			return (TRUE);
		if (chars[0] & ((long long)1 << str[i]))
			return (TRUE);
		i++;
	}
	return (FALSE);
}
