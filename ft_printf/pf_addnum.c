/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_addnum.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/12 02:16:09 by pholster       #+#    #+#                */
/*   Updated: 2019/04/24 13:08:29 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	pf_addnum(t_info *info, t_intmax value)
{
	int			i;
	int			len;
	char		*base_str;
	char		*str;
	t_uintmax	num;

	base_str = "0123456789abcdefghijklmnopqrstuvwxyz";
	num = (value < 0) ? -value : value;
	len = ft_unumlen(num);
	if (len == 0)
		return ;
	str = ft_strnew(len);
	if (str == NULL)
		return ;
	i = len;
	while (i != 0)
	{
		i--;
		str[i] = base_str[(num % 10)];
		num /= 10;
	}
	pf_addtobuff(info, str, len);
	free(str);
}
