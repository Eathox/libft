/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putunum_cbase_fd.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/09 12:12:03 by pholster      #+#    #+#                 */
/*   Updated: 2019/08/21 21:50:31 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft/char.h"

#include "unum.h"

bool	ft_putunum_cbase_fd(uintmax_t value, int base, bool up, int fd)
{
	char	*base_str;

	if (up == true)
		base_str = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	else
		base_str = "0123456789abcdefghijklmnopqrstuvwxyz";
	if (base < 2 || base > 36)
		return (true);
	if (value > (uintmax_t)(base - 1))
	{
		if (ft_putunum_cbase_fd((value / base), base, up, fd) == false)
			return (false);
	}
	value = base_str[(value % base)];
	return (ft_putchar_fd(value, fd));
}
