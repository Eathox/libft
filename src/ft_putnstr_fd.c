/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnstr_fd.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/09 12:06:48 by pholster       #+#    #+#                */
/*   Updated: 2019/07/21 22:45:18 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <unistd.h>

void	ft_putnstr_fd(const char *str, size_t n, int fd)
{
	if (str == NULL)
		write(fd, "(null)", n);
	else
		write(fd, str, ft_strnlen(str, n));
}
