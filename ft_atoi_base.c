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

int				ft_atoi_base(const char *str, int base)
{
	char				*base_str;
	unsigned long long	result;
	unsigned long long	lst_val;
	int					isneg;
	int					i;

	i = 0;
	result = 0;
	lst_val = result;
	base_str = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	if (base < 2 || base > 36)
		return (0);
	while (ft_isspace(str[i]))
		i++;
	isneg = (str[i] == '-' && base == 10) ? -1 : 1;
	i += (str[i] == '-' || str[i] == '+');
	while (ft_chrnin(base_str, str[i], base) && lst_val <= result)
	{
		lst_val = result;
		result = (result * base) + ft_chrindex(base_str, str[i]);
		i++;
	}
	if (result > (9223372036854775807 + (isneg == -1)) || lst_val > result)
		return (0 - (isneg == 1));
	return ((int)(result * isneg));
}
