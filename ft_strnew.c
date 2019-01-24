/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnew.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/09 13:57:08 by pholster       #+#    #+#                */
/*   Updated: 2019/01/20 17:36:19 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	size_t	i;
	char	*s;

	i = 0;
	s = (char *)malloc(size + 1);
	if (s == NULL)
		return (NULL);
	while (i <= size)
		s[i++] = '\0';
	return (s);
}
