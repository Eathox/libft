/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa_base.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/03 14:52:39 by pholster       #+#    #+#                */
/*   Updated: 2019/02/25 13:08:38 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base(long long value, int base)
{
	unsigned long long	num;
	int					len;
	char				*base_str;
	char				*str;

	num = (value < 0 && base == 10) ? -value : value;
	len = ft_numlen_base(value, base);
	if (base < 2 || base > 36)
		return (NULL);
	str = ft_strnew(len);
	base_str = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	if (str == NULL)
		return (NULL);
	while ((len - (value < 0 && base == 10)) != 0)
	{
		str[len - 1] = base_str[(num % base)];
		num = num / base;
		len--;
	}
	if (value < 0 && base == 10)
		str[0] = '-';
	return (str);
}
