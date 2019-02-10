/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putendl_fd.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/09 12:10:11 by pholster       #+#    #+#                */
/*   Updated: 2019/02/10 14:27:08 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(const char *s, int fd)
{
	if (s == NULL)
	{
		ft_putendl_fd("(null)", fd);
		return ;
	}
	ft_putstr_fd(s, fd);
	write(fd, "\n", 1);
}
