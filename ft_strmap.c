/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/10 11:22:31 by pholster       #+#    #+#                */
/*   Updated: 2019/01/20 17:25:17 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(const char *s, char (*f)(char))
{
	int		i;
	int		len;
	char	*str;

	i = -1;
	if (f == NULL || s == NULL)
		return (NULL);
	len = ft_strlen(s);
	str = ft_strnew(len);
	if (str == NULL)
		return (NULL);
	while (++i < len)
		str[i] = f(s[i]);
	str[i] = '\0';
	return (str);
}
