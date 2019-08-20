/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_chrindex.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/03 22:38:37 by pholster       #+#    #+#                */
/*   Updated: 2019/08/20 13:49:30 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t		ft_chrindex(char *str, int c)
{
	char	*ptr;

	ptr = ft_memchr(str, c, ft_strlen(str));
	if (ptr == NULL)
		return (-1);
	return ((size_t)ptr - (size_t)str);
}
