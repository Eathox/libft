/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin_arr.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/19 17:00:01 by pholster       #+#    #+#                */
/*   Updated: 2019/02/21 16:55:44 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strjoin_var(int count, ...)
{
	int			i;
	char		*str;
	const char	**arr;
	va_list		args;

	i = 0;
	arr = ft_strarrnew(count);
	if (arr == NULL)
		return (NULL);
	va_start(args, count);
	while (i < count)
	{
		arr[i] = va_arg(args, const char *);
		i++;
	}
	va_end(args);
	str = ft_strjoin_arr(arr);
	ft_memdel((void **)arr);
	return (str);
}
