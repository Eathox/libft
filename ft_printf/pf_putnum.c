/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_putnum.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/16 17:46:23 by pholster       #+#    #+#                */
/*   Updated: 2019/03/31 12:42:32 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	putnbr(long long value)
{
	char				*base_str;
	unsigned long long	num;

	base_str = "0123456789abcdefghijklmnopqrstuvwxyz";
	num = (value < 0) ? -value : value;
	if (num > (unsigned long long)(10 - 1))
		putnbr((num / 10));
	num = base_str[(num % 10)];
	ft_putchar_fd(num, 1);
}

void		pf_putnum(t_info *info)
{
	t_intmax	num;

	if (PF_PRECISION == 0 && pf_iszero(info) == TRUE)
	{
		if (PF_WIDTH != -1)
			pf_putchar(info, ' ');
		return ;
	}
	num = pf_overflowsigned(info);
	putnbr(num);
	PF_PRINTED += PF_VAR_LEN;
}
