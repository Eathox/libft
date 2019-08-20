/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isdigitstr.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/03 16:07:33 by pholster       #+#    #+#                */
/*   Updated: 2019/08/20 13:49:30 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool		ft_isdigitstr(char *str)
{
	size_t	len;

	len = 0;
	if (str[0] == '+' || str[0] == '-')
		len++;
	len += ft_strislen(&str[len], &ft_isdigit);
	return (str[len] == '\0');
}
