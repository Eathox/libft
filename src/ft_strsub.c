/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strsub.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 13:11:37 by pholster       #+#    #+#                */
/*   Updated: 2019/08/20 13:49:30 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char *str, size_t start, size_t len)
{
	char	*ret;

	ret = ft_strnew(len);
	if (ret == NULL)
		return (NULL);
	ft_memcpy(ret, &str[start], len);
	ret[len] = '\0';
	return (ret);
}
