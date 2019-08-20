/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_termsetcolorbg_fd.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/18 14:42:21 by pholster       #+#    #+#                */
/*   Updated: 2019/08/10 16:25:08 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool	ft_termsetcolorbg_fd(t_color color, int fd)
{
	if (ft_putstr_fd("\e[48;5;", fd) == FALSE)
		return (FALSE);
	if (ft_putnum_fd(color, fd) == FALSE)
		return (FALSE);
	return (ft_putchar_fd('m', fd));
}
