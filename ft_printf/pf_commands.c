/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_commands.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/18 15:47:54 by pholster       #+#    #+#                */
/*   Updated: 2019/03/31 12:44:21 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pf_commands(const char *str)
{
	int	len;

	len = ft_strislen(str, &ft_isdigit);
	if (*str == ']')
	{
		ft_termcommand(0);
		return (2);
	}
	if (ft_strnequ_nocase(str, "clr]", 4))
	{
		ft_termclr();
		return (5);
	}
	if (len != 0 && str[len] == ']')
	{
		ft_termcommand(ft_atoi(str));
		return (2 + len);
	}
	return (0);
}
