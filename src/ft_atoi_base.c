/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi_base.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/10 11:30:39 by pholster       #+#    #+#                */
/*   Updated: 2019/07/21 22:45:17 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

intmax_t		ft_atoi_base(const char *str, int base)
{
	char		*base_str;
	uintmax_t	result;
	uintmax_t	lst_val;
	int			isneg;
	size_t		i;

	result = 0;
	lst_val = result;
	base_str = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	if (base < 2 || base > 36)
		return (0);
	i = ft_strislen(str, &ft_isspace);
	isneg = (str[i] == '-' && base == 10) ? -1 : 1;
	i += (str[i] == '-' || str[i] == '+');
	while (ft_chrnin(base_str, str[i], base) && lst_val <= result)
	{
		lst_val = result;
		result = (result * base) + ft_chrindex(base_str, str[i]);
		i++;
	}
	if (lst_val > result ||
		result > (uintmax_t)(9223372036854775807 + (isneg == -1)))
		return (0 - (isneg == 1));
	return ((intmax_t)(result * isneg));
}
