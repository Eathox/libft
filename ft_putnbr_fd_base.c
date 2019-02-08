/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_fd_base.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/09 12:12:03 by pholster       #+#    #+#                */
/*   Updated: 2019/02/04 17:42:02 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd_base(int value, int fd, int base)
{
	char			*bstr;
	unsigned int	num;

	bstr = "0123456789ABCDEF";
	num = (value < 0 && base == 10) ? -value : value;
	if (base < 2 || base > 16)
		return ;
	if (value < 0 && base == 10)
		write(fd, "-", 1);
	if (num > (unsigned int)(base - 1))
		ft_putnbr_fd_base((num / base), fd, base);
	num = bstr[(num % base)];
	write(fd, &num, 1);
}
