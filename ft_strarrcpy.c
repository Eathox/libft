/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strarrcpy.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/18 16:18:39 by pholster       #+#    #+#                */
/*   Updated: 2019/06/15 23:36:05 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	**ft_strarrcpy(char **dst, const char **src)
{
	size_t		i;

	i = 0;
	while (src[i] != NULL)
	{
		dst[i] = ft_strdup(src[i]);
		if (dst[i] == NULL)
			return (NULL);
		i++;
	}
	dst[i] = NULL;
	return (dst);
}
