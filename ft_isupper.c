/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isupper.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/06 16:57:45 by pholster       #+#    #+#                */
/*   Updated: 2019/07/20 17:28:23 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

/*
** return (((0x40 - c) < 0) && ((c - 0x5B) < 0));
*/

t_bool		ft_isupper(int c)
{
	return (c >= 'A' && c <= 'Z');
}
