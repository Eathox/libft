/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin_var.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/19 17:00:01 by pholster       #+#    #+#                */
/*   Updated: 2019/02/25 13:26:44 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strjoin_var(int count, ...)
{
	size_t		i;
	char		*str;
	const char	**arr;
	va_list		args;

	i = 0;
	arr = (const char **)ft_strarrnew(count);
	if (arr == NULL)
		return (NULL);
	va_start(args, count);
	while (i < (size_t)count)
	{
		arr[i] = va_arg(args, const char *);
		i++;
	}
	va_end(args);
	str = ft_strjoin_arr(arr);
	ft_memdel((void **)arr);
	return (str);
}
