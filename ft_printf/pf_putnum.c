/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_putnum.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/16 17:46:23 by pholster       #+#    #+#                */
/*   Updated: 2019/04/01 13:35:11 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	putnbr(long long value, int fd)
{
	char				*base_str;
	unsigned long long	num;

	base_str = "0123456789abcdefghijklmnopqrstuvwxyz";
	num = (value < 0) ? -value : value;
	if (num > (unsigned long long)(10 - 1))
		putnbr((num / 10), fd);
	num = base_str[(num % 10)];
	ft_putchar_fd(num, fd);
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
	putnbr(num, PF_FD);
	PF_PRINTED += PF_VAR_LEN;
}
