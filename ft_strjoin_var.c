/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin_var.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/19 17:00:01 by pholster       #+#    #+#                */
/*   Updated: 2019/02/21 13:34:46 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*freeret(char *ret, char **arr, va_list args)
{
	va_end(args);
	if (arr != NULL)
		free(arr);
	return (ret);
}

static size_t	getstrs(char **arr, int count, va_list args)
{
	size_t	len;
	int		i;

	i = 0;
	len = 0;
	while (i < count)
	{
		arr[i] = va_arg(args, char *);
		len += ft_strlen(arr[i]);
		i++;
	}
	return (len);
}

static char		*joinstrs(char *str, char **arr, int count)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	while (j < count)
	{
		if (arr[j][k] == '\0')
		{
			k = 0;
			j++;
			continue;
		}
		str[i] = arr[j][k];
		i++;
		k++;
	}
	return (str);
}

char			*ft_strjoin_var(int count, ...)
{
	int		i;
	size_t	len;
	char	**arr;
	char	*str;
	va_list	args;

	i = 0;
	len = 0;
	va_start(args, count);
	arr = ft_strarrnew(count);
	if (arr == NULL)
		return (freeret(NULL, NULL, args));
	len = getstrs(arr, count, args);
	str = ft_strnew(getstrs(arr, count, args));
	if (str == NULL)
		return (freeret(NULL, arr, args));
	str = joinstrs(str, arr, count);
	return (freeret(str, arr, args));
}
