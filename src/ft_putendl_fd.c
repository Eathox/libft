/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putendl_fd.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/09 12:10:11 by pholster       #+#    #+#                */
/*   Updated: 2019/07/21 22:45:18 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <unistd.h>

void	ft_putendl_fd(const char *str, int fd)
{
	if (str == NULL)
	{
		ft_putendl_fd("(null)", fd);
		return ;
	}
	ft_putstr_fd(str, fd);
	write(fd, "\n", 1);
}
