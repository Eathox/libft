/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strisfloat.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/03 16:07:33 by pholster      #+#    #+#                 */
/*   Updated: 2019/08/21 21:30:12 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft/char.h"

#include "str.h"

bool		ft_strisfloat(const char *str)
{
	size_t	len;

	len = 0;
	if (str[0] == '+' || str[0] == '-')
		len++;
	len += ft_strislen(&str[len], &ft_isdigit);
	if (str[len] != '.')
		return (false);
	len++;
	len += ft_strislen(&str[len], &ft_isdigit);
	return (str[len] == '\0');
}
