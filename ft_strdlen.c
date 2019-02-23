/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdlen.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 15:20:03 by pholster       #+#    #+#                */
/*   Updated: 2019/02/24 00:00:34 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strdlen(const char *str, const char *dlm)
{
	size_t	len;

	len = 0;
	if (str == NULL || dlm == NULL)
		return (0);
	while (str[len] != '\0' && ft_chrin(dlm, str[len]) == FALSE)
		len++;
	return (len);
}
