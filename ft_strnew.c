/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnew.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/09 13:57:08 by pholster       #+#    #+#                */
/*   Updated: 2019/02/14 19:21:30 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	size_t	i;
	char	*s;

	i = 0;
	s = (char *)ft_memalloc(sizeof(char) * (size + 1));
	if (s == NULL)
		return (NULL);
	return (s);
}
