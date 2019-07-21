/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_termsetcolorbg_fd.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/18 14:42:21 by pholster       #+#    #+#                */
/*   Updated: 2019/07/21 22:45:17 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_termsetcolorbg_fd(t_color color, int fd)
{
	ft_putstr_fd("\e[48;5;", fd);
	ft_putnum_fd(color, fd);
	ft_putchar_fd('m', fd);
}
