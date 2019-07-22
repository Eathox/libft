/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_chrin.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/09 17:42:01 by pholster       #+#    #+#                */
/*   Updated: 2019/07/21 22:45:18 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_bool		ft_chrin(const char *str, int c)
{
	return (ft_chrindex(str, c) != -1);
}
