/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnstr_fd.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/09 12:06:48 by pholster       #+#    #+#                */
/*   Updated: 2019/03/20 17:53:00 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnstr_fd(const char *str, int fd, size_t n)
{
	if (str == NULL)
		write(fd, "(null)", n);
	else
		write(fd, str, ft_strnlen(str, n));
}
