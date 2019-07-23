/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putbool_fd.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/14 16:10:37 by pholster       #+#    #+#                */
/*   Updated: 2019/07/23 18:07:56 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_bool	ft_putbool_fd(t_bool boolean, int fd)
{
	if (boolean == FALSE)
		return (ft_putstr_fd("FALSE", fd));
	return (ft_putstr_fd("TRUE", fd));
}
