/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi_base.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/10 11:30:39 by pholster       #+#    #+#                */
/*   Updated: 2019/02/12 15:09:51 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_atoi_base(const char *s, int base)
{
	char				*bstr;
	unsigned long long	result;
	int					isneg;
	int					i;

	i = 0;
	result = 0;
	bstr = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	if (base < 2 || base > 36)
		return (0);
	while (ft_isspace(s[i]))
		i++;
	isneg = (s[i] == '-' && base == 10) ? -1 : 1;
	i += ft_chrin("+-", s[i]);
	while (ft_chrnin(bstr, s[i], base))
	{
		result = (result * base) + ft_chrindex(bstr, s[i]);
		i++;
	}
	if (result > (9223372036854775807 + (isneg == -1)))
		return (0 - (isneg == 1));
	return ((int)(result * isneg));
}
