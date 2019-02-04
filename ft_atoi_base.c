/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi_base.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/10 11:30:39 by pholster       #+#    #+#                */
/*   Updated: 2019/02/04 10:50:42 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_atoi_base(const char *s, int base)
{
	char				*bstr;
	unsigned long long	result;
	int					isneg;
	int					i;

	i = 0;
	isneg = 1;
	result = 0;
	bstr = "0123456789abcdef";
	if (base < 2 || base > 16)
		return (0);
	while (ft_isspace(s[i]))
		i++;
	if (s[i] == '-' && base == 10)
		isneg = -1;
	if (ft_chrin("+-", s[i]))
		i++;
	while (ft_chrnin(bstr, s[i], base))
	{
		result = (result * base) + ft_chrindex(bstr, s[i]);
		i++;
	}
	if (result > (9223372036854775807 + (isneg == -1)))
		return (0 - (isneg == 1));
	return ((int)(result * isneg));
}
