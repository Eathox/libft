/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_islower.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/06 16:57:43 by pholster       #+#    #+#                */
/*   Updated: 2019/07/23 14:14:27 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/typedefs.h"

/*
** return (((0x60 - c) < 0) && ((c - 0x7B) < 0));
*/

t_bool		ft_islower(int c)
{
	return (c >= 'a' && c <= 'z');
}
