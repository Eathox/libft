/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa_base.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/03 14:52:39 by pholster       #+#    #+#                */
/*   Updated: 2019/02/03 15:40:38 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base(int value, int base)
{
	unsigned int	num;
	unsigned int	len;
	char			*bstr;
	char			*str;

	num = (value < 0) ? -value : value;
	len = ft_intlen_base(value, base);
	str = ft_strnew(len);
	bstr = "0123456789ABCDEF";
	if (str == NULL || base < 0 || base > 16)
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
