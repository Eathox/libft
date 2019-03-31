/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_isnegativeint.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/21 19:21:03 by pholster       #+#    #+#                */
/*   Updated: 2019/03/31 12:42:32 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pf_isnegativeint(t_info *info)
{
	return (pf_issignint(info) && pf_isnegative(info));
}
