/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdtrim.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 14:53:11 by pholster       #+#    #+#                */
/*   Updated: 2019/02/06 03:27:29 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdtrim(const char *s, const char *delims)
{
	char	*str;
	int		len;
	int		i;

	i = 0;
	if (s == NULL)
		return (NULL);
	len = (int)ft_strlen(s);
	while (ft_chrin(delims, s[i]) && s[i] != '\0')
		i++;
	if (i == len)
		return (ft_strnew(0));
	while (ft_chrin(delims, s[(len - 1)]) && (len - 1) > i)
		len--;
	str = ft_strndup(&s[i], (size_t)(len - i));
	return (str);
}
