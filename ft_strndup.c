/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strndup.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/07 16:33:10 by pholster       #+#    #+#                */
/*   Updated: 2019/04/11 21:41:16 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strndup(const char *str, size_t n)
{
	size_t	len;
	char	*dup;

	len = 0;
	while (len < n && str[len] != '\0')
		len++;
	dup = ft_strnew(len);
	if (dup == NULL)
		return (NULL);
	ft_strncpy(dup, str, len);
	return (dup);
}
