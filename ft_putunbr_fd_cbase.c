/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putunbr_fd_cbase.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/09 12:12:03 by pholster       #+#    #+#                */
/*   Updated: 2019/03/21 12:25:38 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putunbr_fd_cbase(unsigned long long value, int fd, int base, int up)
{
	char				*base_str;

	if (up == TRUE)
		base_str = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	else
		base_str = "0123456789abcdefghijklmnopqrstuvwxyz";
	if (base < 2 || base > 36)
		return ;
	if (value > (unsigned long long)(base - 1))
		ft_putunbr_fd_cbase((value / base), fd, base, up);
	value = base_str[(value % base)];
	ft_putchar_fd(value, fd);
}
