/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isdigitstr.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/03 16:07:33 by pholster       #+#    #+#                */
/*   Updated: 2019/02/24 13:49:29 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isdigitstr(const char *str)
{
	size_t	len;

	len = ft_strislen(str, &ft_isdigit);
	return (str[len] == '\0');
}
