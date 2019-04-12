/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strarrcpy_var.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/18 16:18:39 by pholster       #+#    #+#                */
/*   Updated: 2019/03/23 11:53:51 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	**ft_strarrcpy_var(char **dst, int count, ...)
{
	size_t		i;
	va_list		args;

	i = 0;
	va_start(args, count);
	while (i < (size_t)count)
	{
		dst[i] = ft_strdup(va_arg(args, char *));
		if (dst[i] == NULL)
		{
			return (NULL);
			va_end(args);
		}
		i++;
	}
	va_end(args);
	return (dst);
}
