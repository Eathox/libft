/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_termsetrgbcolorbg_fd.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/18 14:42:21 by pholster      #+#    #+#                 */
/*   Updated: 2019/08/21 21:45:20 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft/str.h"
#include "ft/num.h"
#include "ft/char.h"

#include "term.h"

bool	ft_termsetrgbcolorbg_fd(t_color rgb, int fd) {
	if (ft_putstr_fd("\033[48;2;", fd) == false)
		return (false);
	if (ft_putnum_fd(rgb.r, fd) == false)
		return (false);
	if (ft_putchar_fd(';', fd) == false)
		return (false);
	if (ft_putnum_fd(rgb.g, fd) == false)
		return (false);
	if (ft_putchar_fd(';', fd) == false)
		return (false);
	if (ft_putnum_fd(rgb.b, fd) == false)
		return (false);
	return (ft_putchar_fd('m', fd));
}
