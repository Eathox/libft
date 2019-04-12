/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_commands.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/18 15:47:54 by pholster       #+#    #+#                */
/*   Updated: 2019/04/01 13:28:03 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

// int		pf_commands(t_info *info, const char *str)
// {
// 	int	len;

// 	len = ft_strislen(str, &ft_isdigit);
// 	if (*str == ']')
// 	{
// 		ft_termcommand_fd(0, PF_FD);
// 		return (2);
// 	}
// 	if (ft_strnequ_nocase(str, "clr]", 4))
// 	{
// 		ft_termclr_fd(PF_FD);
// 		return (5);
// 	}
// 	if (len != 0 && str[len] == ']')
// 	{
// 		ft_termcommand_fd(ft_atoi(str), PF_FD);
// 		return (2 + len);
// 	}
// 	return (0);
// }

int		pf_commands(t_info *info, const char *str)
{
	(void)info;
	(void)str;
	return (0);
}
