/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnum_cbase_fd.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/09 12:12:03 by pholster       #+#    #+#                */
/*   Updated: 2019/07/21 22:45:17 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_putnum_cbase_fd(intmax_t value, int base, t_bool up, int fd)
{
	char		*base_str;
	uintmax_t	num;

	if (up == TRUE)
		base_str = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	else
		base_str = "0123456789abcdefghijklmnopqrstuvwxyz";
	num = (value < 0 && base == 10) ? -value : value;
	if (base < 2 || base > 36)
		return ;
	if (value < 0 && base == 10)
		ft_putchar_fd('-', fd);
	if (num > (uintmax_t)(base - 1))
		ft_putnum_cbase_fd((num / base), base, up, fd);
	num = base_str[(num % base)];
	ft_putchar_fd(num, fd);
}
