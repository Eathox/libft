/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strarrlen.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/07 16:33:10 by pholster       #+#    #+#                */
/*   Updated: 2019/01/23 14:00:22 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strarrlen(const char **arr)
{
	size_t	len;

	len = 0;
	while (arr[len] != NULL)
		len++;
	return (len);
}
