/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_termsetcolorbg_fd.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/18 14:42:21 by pholster      #+#    #+#                 */
/*   Updated: 2019/08/21 21:44:31 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft/char.h"
#include "ft/str.h"
#include "ft/num.h"

#include "term.h"

bool	ft_termsetcolorbg_fd(t_uint8 color, int fd) {
	if (ft_putstr_fd("\033[48;5;", fd) == false)
		return (false);
	if (ft_putnum_fd(color, fd) == false)
		return (false);
	return (ft_putchar_fd('m', fd));
}
