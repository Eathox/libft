/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_addnum.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/12 02:16:09 by pholster       #+#    #+#                */
/*   Updated: 2019/04/12 12:34:53 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	pf_addnum(t_info *info, t_intmax value)
{
	int		i;
	int		len;
	char	*base_str;
	char	*str;

	base_str = "0123456789abcdefghijklmnopqrstuvwxyz";
	value = (value < 0) ? -value : value;
	len = ft_numlen(value);
	if (len == 0)
		return ;
	str = ft_strnew(len);
	if (str == NULL)
		return ;
	i = len;
	while (i != 0)
	{
		i--;
		str[i] = base_str[(value % 10)];
		value /= 10;
	}
	pf_lstaddptr(info, str, len);
}
