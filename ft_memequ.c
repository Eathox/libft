/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memequ.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 17:53:02 by pholster       #+#    #+#                */
/*   Updated: 2019/03/16 23:05:10 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memequ(const void *str1, const void *str2, size_t len)
{
	return (ft_memcmp(str1, str2, len) == 0);
}
