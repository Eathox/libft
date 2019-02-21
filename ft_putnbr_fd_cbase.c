/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_fd_cbase.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/09 12:12:03 by pholster       #+#    #+#                */
/*   Updated: 2019/02/21 16:20:35 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd_cbase(long long value, int fd, int base, int up)
{
	char				*base_str;
	unsigned long long	num;

	if (up == TRUE)
		base_str = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	else
		base_str = "0123456789abcdefghijklmnopqrstuvwxyz";
	num = (value < 0 && base == 10) ? -value : value;
	if (base < 2 || base > 36)
		return ;
	if (value < 0 && base == 10)
		ft_putchar_fd('-', fd);
	if (num > (unsigned long long)(base - 1))
		ft_putnbr_fd_base((num / base), fd, base);
	num = base_str[(num % base)];
	ft_putchar_fd(num, fd);
}
