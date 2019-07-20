/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isblank.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/30 00:14:15 by pholster       #+#    #+#                */
/*   Updated: 2019/07/20 17:28:09 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

t_bool		ft_isblank(int c)
{
	return (c == ' ' || c == '\t');
}
