/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putendl_fd.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/09 12:10:11 by pholster       #+#    #+#                */
/*   Updated: 2019/07/23 18:27:16 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_bool	ft_putendl_fd(const char *str, int fd)
{
	if (str == NULL)
		return (ft_putendl_fd("(null)", fd));
	if (ft_putstr_fd(str, fd) == FALSE)
		return (FALSE);
	return (ft_putchar_fd('\n', fd));
}
