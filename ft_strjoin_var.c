/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin_var.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/19 17:00:01 by pholster       #+#    #+#                */
/*   Updated: 2019/02/19 17:27:26 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	totallen(char **arr)
{
	size_t	len;
	int		i;

	i = 0;
	len = 0;
	while (arr[i] != NULL)
	{
		len += ft_strlen(arr[i]);
		i++;
	}
	return (len);
}

static char		**strarr(int count, va_list args)
{
	int		i;
	char	**arr;

	i = 0;
	arr = ft_newstrarr(count);
	if (arr == NULL)
		return (NULL);
	while (i < count)
	{
		arr[i] = va_arg(args, char *);
		i++;
	}
	return (arr);
}

char			*ft_strjoin_var(int count, ...)
{
	int		i;
	char	**arr;
	char	*str;
	va_list	args;

	i = 0;
	va_start(args, count);
	arr = strarr(count, args);
	if (arr == NULL)
	{
		va_end(args);
		return (NULL);
	}
	str = ft_strnew(totallen(arr));
	while (arr[i] != NULL)
	{
		ft_strcat(str, (char *)arr[i]);
		i++;
	}
	va_end(args);
	ft_memdel(&arr);
	return (str);
}
