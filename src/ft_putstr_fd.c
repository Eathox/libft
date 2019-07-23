/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putstr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/09 12:06:48 by pholster       #+#    #+#                */
/*   Updated: 2019/07/23 14:36:17 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <unistd.h>

void	ft_putstr_fd(const char *str, int fd)
{
	if (str == NULL)
		write(fd, "(null)", 6);
	else
		write(fd, str, ft_strlen(str));
}
