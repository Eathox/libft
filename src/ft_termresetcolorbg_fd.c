/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_termresetcolorbg_fd.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/18 14:42:21 by pholster       #+#    #+#                */
/*   Updated: 2019/07/23 14:28:01 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_termresetcolorbg_fd(int fd)
{
	write(fd, "\e[49m\e[K", 9);
}
