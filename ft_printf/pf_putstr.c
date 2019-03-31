/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_putstr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/07 17:30:53 by pholster       #+#    #+#                */
/*   Updated: 2019/03/31 12:42:32 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pf_putstr(t_info *info, char *str)
{
	size_t	len;

	if (str == NULL)
	{
		len = 6;
		write(1, "(null)", len);
	}
	else
	{
		len = ft_strdlen(str, "%");
		write(1, str, len);
	}
	PF_PRINTED += len;
	return ((len > 0) ? len - 1 : len);
}
