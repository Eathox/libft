/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_ispositiveint.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/21 19:21:03 by pholster       #+#    #+#                */
/*   Updated: 2019/07/20 20:45:12 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_bool	pf_ispositiveint(t_info *info)
{
	return (pf_issignint(info) && info->isnegative == FALSE);
}
