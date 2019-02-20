/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/10 11:22:31 by pholster       #+#    #+#                */
/*   Updated: 2019/02/01 12:07:07 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(const char *str, char (*f)(char))
{
	int		i;
	int		len;
	char	*ret;

	i = 0;
	if (f == NULL || str == NULL)
		return (NULL);
	len = (int)ft_strlen(str);
	ret = ft_strnew(len);
	if (ret == NULL)
		return (NULL);
	while (i < len)
	{
		ret[i] = f(str[i]);
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
