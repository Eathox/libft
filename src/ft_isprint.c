/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isprint.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/09 11:43:50 by pholster       #+#    #+#                */
/*   Updated: 2019/07/23 14:14:31 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/typedefs.h"

t_bool		ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}
