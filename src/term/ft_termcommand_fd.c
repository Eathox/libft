/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_termcommand_fd.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/19 12:21:06 by pholster      #+#    #+#                 */
/*   Updated: 2019/08/21 21:42:12 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft/char.h"
#include "ft/str.h"
#include "ft/num.h"

#include "term.h"

bool	ft_termcommand_fd(int command, int fd)
{
	if (ft_putstr_fd("\033[", fd) == false)
		return (false);
	if (ft_putnum_fd(command, fd) == false)
		return (false);
	return (ft_putchar_fd('m', fd));
}
