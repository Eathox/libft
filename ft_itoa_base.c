/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa_base.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/03 14:52:39 by pholster       #+#    #+#                */
/*   Updated: 2019/02/14 19:33:18 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base(long long value, int base)
{
	unsigned long long	num;
	int					len;
	char				*bstr;
	char				*str;

	num = (value < 0 && base == 10) ? -value : value;
	len = ft_numlen_base(value, base);
	len -= (value < 0 && base == 10);
	if (base < 2 || base > 36)
		return (NULL);
	str = ft_strnew(len);
	bstr = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	if (str == NULL)
		return (NULL);
	while (len != 0)
	{
		str[len] = bstr[(num % base)];
		num = num / base;
		len--;
	}
	if (value < 0 && base == 10)
		str[0] = '-';
	return (str);
}
