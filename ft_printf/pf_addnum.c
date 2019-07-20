/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_addnum.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/12 02:16:09 by pholster       #+#    #+#                */
/*   Updated: 2019/07/20 16:12:33 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	pf_addnum(t_info *info, intmax_t value)
{
	intmax_t	num;

	num = (value < 0) ? -value : value;
	pf_addunum(info, num, ft_unumlen(num), 10);
}
