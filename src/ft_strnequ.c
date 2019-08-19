/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnequ.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 10:54:47 by pholster       #+#    #+#                */
/*   Updated: 2019/08/19 19:51:35 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool	ft_strnequ(const char *str1, const char *str2, size_t n)
{
	return (ft_strncmp(str1, str2, n) == 0);
}
