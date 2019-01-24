/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 14:53:11 by pholster       #+#    #+#                */
/*   Updated: 2019/01/20 17:27:58 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*str;
	int		len;
	int		i;

	i = 0;
	if (s == NULL)
		return (NULL);
	len = ft_strlen(s);
	while (ft_chrin(" \n\t", s[i]) && s[i] != '\0')
		i++;
	if (i == len)
		return (ft_strnew(0));
	while (ft_chrin(" \n\t", s[(len - 1)]) && (len - 1) > i)
		len--;
	str = ft_strndup(&s[i], (size_t)(len - i));
	if (str == NULL)
		return (NULL);
	return (str);
}
