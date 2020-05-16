/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putendl_fd.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/09 12:10:11 by pholster      #+#    #+#                 */
/*   Updated: 2019/08/21 21:30:23 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft/char.h"

#include "str.h"

bool	ft_putendl_fd(const char *str, int fd)
{
	if (ft_putstr_fd(str, fd) == false)
		return (false);
	return (ft_putchar_fd('\n', fd));
}
