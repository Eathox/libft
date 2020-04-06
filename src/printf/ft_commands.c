/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_commands.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/18 15:47:54 by pholster      #+#    #+#                 */
/*   Updated: 2019/08/21 21:25:56 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft/char.h"
#include "ft/str.h"

#include "printf.h"
#include "priv.h"

size_t		ft_commands(t_info *info, const char *str)
{
	size_t	len;

	len = ft_strislen(str, &ft_isdigit);
	if (*str == ']')
	{
		ft_addtobuff(info, "\033[0m", 5);
		return (2);
	}
	if (ft_strnequ_nocase(str, "clr]", 4))
	{
		ft_addtobuff(info, "\033[1;1H\033[2J\n", 12);
		return (5);
	}
	if (len != 0 && str[len] == ']')
	{
		ft_addtobuff(info, "\033[", 3);
		ft_addtobuff(info, str, len);
		ft_addtobuff(info, "m", 1);
		return (2 + len);
	}
	return (0);
}
