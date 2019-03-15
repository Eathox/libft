/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lststrsort.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/15 17:28:11 by pholster       #+#    #+#                */
/*   Updated: 2019/03/15 17:37:10 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lststrsort(const void *str1, size_t n1, const void *str2, size_t n2)
{
	return (ft_memcmp(str1, str2, ft_max(n1, n2) > 0));
}
