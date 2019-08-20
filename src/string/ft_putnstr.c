/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/09 12:06:48 by pholster       #+#    #+#                */
/*   Updated: 2019/08/20 13:49:30 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool	ft_putnstr(char *str, size_t n)
{
	return (ft_putnstr_fd(str, n, 1));
}
