/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_chrindex.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/03 22:38:37 by pholster       #+#    #+#                */
/*   Updated: 2019/07/21 22:45:18 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

ssize_t		ft_chrindex(const char *str, int c)
{
	char	*ptr;

	if (str == NULL)
		return (-1);
	ptr = ft_memchr(str, c, ft_strlen(str));
	if (ptr == NULL)
		return (-1);
	return ((size_t)ptr - (size_t)str);
}
