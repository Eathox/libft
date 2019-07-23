/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_termclr_fd.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/26 14:51:28 by pholster       #+#    #+#                */
/*   Updated: 2019/07/23 16:56:51 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_termclr_fd(int fd)
{
	ft_putstr_fd("\e[1;1H\e[2J\n", fd);
}
