/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa_base.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/03 14:52:39 by pholster       #+#    #+#                */
/*   Updated: 2019/02/10 14:12:43 by pholster      ########   odam.nl         */
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
	if (base < 2 || base > 16)
		return (NULL);
	str = ft_strnew(len);
	bstr = "0123456789ABCDEF";
	if (str == NULL)
		return (NULL);
	while ((len - (value < 0 && base == 10)) != 0)
	{
		str[(len - 1)] = bstr[(num % base)];
		num = num / base;
		len--;
	}
	if (value < 0 && base == 10)
		str[0] = '-';
	return (str);
}
