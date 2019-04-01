/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_isnegativeint.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/21 19:21:03 by pholster       #+#    #+#                */
/*   Updated: 2019/04/01 13:28:03 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		pf_isnegativeint(t_info *info)
{
	return (pf_issignint(info) && pf_isnegative(info));
}
