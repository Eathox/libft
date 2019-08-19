/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strsub.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 13:11:37 by pholster       #+#    #+#                */
/*   Updated: 2019/08/19 19:52:36 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(const char *str, size_t start, size_t len)
{
	char	*ret;

	ret = ft_strnew(len);
	if (ret == NULL)
		return (NULL);
	ft_memcpy(ret, &str[start], len);
	ret[len] = '\0';
	return (ret);
}
