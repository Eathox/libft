/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isblank.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/30 00:14:15 by pholster       #+#    #+#                */
/*   Updated: 2019/03/30 00:14:15 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isblank(int c)
{
	return (c == ' ' || c == '\t');
}
