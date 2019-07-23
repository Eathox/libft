/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putunum_cbase_fd.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/09 12:12:03 by pholster       #+#    #+#                */
/*   Updated: 2019/07/23 18:22:20 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_bool	ft_putunum_cbase_fd(uintmax_t value, int base, t_bool up, int fd)
{
	char	*base_str;

	if (up == TRUE)
		base_str = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	else
		base_str = "0123456789abcdefghijklmnopqrstuvwxyz";
	if (base < 2 || base > 36)
		return (TRUE);
	if (value > (uintmax_t)(base - 1))
	{
		if (ft_putunum_cbase_fd((value / base), base, up, fd) == FALSE)
			return (FALSE);
	}
	value = base_str[(value % base)];
	return (ft_putchar_fd(value, fd));
}
