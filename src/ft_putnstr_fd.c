/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnstr_fd.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/09 12:06:48 by pholster       #+#    #+#                */
/*   Updated: 2019/07/23 16:54:39 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <unistd.h>

t_bool	ft_putnstr_fd(const char *str, size_t n, int fd)
{
	if (str == NULL)
		return (write(fd, "(null)", n) != -1);
	return (write(fd, str, ft_strnlen(str, n)) != -1);
}
