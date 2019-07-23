/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnchar_fd.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/09 12:05:27 by pholster       #+#    #+#                */
/*   Updated: 2019/07/23 14:19:54 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/typedefs.h"
#include <unistd.h>

void	ft_putnchar_fd(char c, size_t n, int fd)
{
	while (n > 0)
	{
		write(fd, &c, 1);
		n--;
	}
}
