/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isdigitstr.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/03 16:07:33 by pholster       #+#    #+#                */
/*   Updated: 2019/06/20 23:20:11 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_isdigitstr(const char *str)
{
	size_t	len;

	len = 0;
	if (str[0] == '+' || str[0] == '-')
		len++;
	len += ft_strislen(&str[len], &ft_isdigit);
	return (str[len] == '\0');
}
