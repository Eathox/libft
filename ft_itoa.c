/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/10 13:42:13 by pholster       #+#    #+#                */
/*   Updated: 2019/01/31 17:48:06 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int value)
{
	return (ft_itoa_base(value, 10));
}

/*
char	*ft_itoa(int n)
{
	char			*s;
	unsigned int	i;
	unsigned int	len;

	i = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = ft_intlen(n);
	s = ft_strnew(len);
	if (s == NULL)
		return (NULL);
	if (n < 0)
	{
		s[i] = '-';
		i++;
	}
	if (n < 0)
		n = -n;
	while (i != len)
	{
		s[(len - 1)] = n % 10 + '0';
		n = n / 10;
		len--;
	}
	return (s);
}
*/