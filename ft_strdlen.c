/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdlen.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 15:20:03 by pholster       #+#    #+#                */
/*   Updated: 2019/01/19 17:56:53 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strdlen(const char *s, char *delims)
{
	size_t	len;

	len = 0;
	if (s == NULL || delims == NULL)
		return (0);
	while (s[len] != '\0' && ft_chrin(delims, s[len]) == FALSE)
		len++;
	return (len);
}
