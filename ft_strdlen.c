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

int		ft_strdlen(const char *s, char *set)
{
	int	i;

	i = 0;
	if (s == NULL || set == NULL)
		return (0);
	while (s[i] != '\0' && ft_chrin(set, s[i]) == FALSE)
		i++;
	return (i);
}
