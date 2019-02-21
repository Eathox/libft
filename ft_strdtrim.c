/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdtrim.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 14:53:11 by pholster       #+#    #+#                */
/*   Updated: 2019/02/21 13:31:48 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdtrim(const char *str, const char *delims)
{
	char	*ret;
	int		len;
	int		i;

	i = 0;
	if (str == NULL)
		return (NULL);
	len = (int)ft_strlen(str);
	while (ft_chrin(delims, str[i]) && str[i] != '\0')
		i++;
	if (i == len)
		return (ft_strnew(0));
	while (ft_chrin(delims, str[(len - 1)]) && (len - 1) > i)
		len--;
	ret = ft_strndup(&str[i], (size_t)(len - i));
	return (ret);
}
