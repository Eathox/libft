/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_printbackpad.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/07 14:15:04 by pholster       #+#    #+#                */
/*   Updated: 2019/03/31 12:42:32 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		pf_printbackpad(t_info *info)
{
	int		len;
	int		i;

	i = PF_PADPRINTED;
	len = ft_max(0, PF_WIDTH) - PF_VAR_LEN;
	if (PF_FLAG_MIN == FALSE)
		len = 0;
	while (i < len)
	{
		pf_putchar(info, ' ');
		i++;
	}
}
