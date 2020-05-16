/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnum_cbase_fd.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/09 12:12:03 by pholster      #+#    #+#                 */
/*   Updated: 2019/08/21 21:17:42 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft/char.h"

#include "num.h"

bool	ft_putnum_cbase_fd(intmax_t value, int base, bool up, int fd)
{
	char		*base_str;
	uintmax_t	num;

	if (up == true)
		base_str = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	else
		base_str = "0123456789abcdefghijklmnopqrstuvwxyz";
	num = (value < 0 && base == 10) ? -value : value;
	if (base < 2 || base > 36)
		return (true);
	if (value < 0 && base == 10)
	{
		if (ft_putchar_fd('-', fd) == false)
			return (false);
	}
	if (num > (uintmax_t)(base - 1))
	{
		if (ft_putnum_cbase_fd((num / base), base, up, fd) == false)
			return (false);
	}
	num = base_str[(num % base)];
	return (ft_putchar_fd(num, fd));
}
