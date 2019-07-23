/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putchar_fd.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/09 12:05:27 by pholster       #+#    #+#                */
/*   Updated: 2019/07/23 16:58:39 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/typedefs.h"
#include <unistd.h>

t_bool	ft_putchar_fd(char c, int fd)
{
	return (write(fd, &c, 1) != -1);
}
