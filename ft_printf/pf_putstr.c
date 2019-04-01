/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_putstr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/07 17:30:53 by pholster       #+#    #+#                */
/*   Updated: 2019/04/01 13:28:03 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		pf_putstr(t_info *info, char *str)
{
	size_t	len;

	if (str == NULL)
	{
		len = 6;
		write(PF_FD, "(null)", len);
	}
	else
	{
		len = ft_strdlen(str, "%");
		write(PF_FD, str, len);
	}
	PF_PRINTED += len;
	return ((len > 0) ? len - 1 : len);
}
