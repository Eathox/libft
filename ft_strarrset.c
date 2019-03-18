/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strarrset.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/18 16:18:39 by pholster       #+#    #+#                */
/*   Updated: 2019/03/18 16:22:08 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strarrset(char **arr, int count, ...)
{
	size_t		i;
	va_list		args;

	i = 0;
	va_start(args, count);
	while (i < (size_t)count)
	{
		arr[i] = ft_strdup(va_arg(args, char *));
		i++;
	}
	va_end(args);
}
