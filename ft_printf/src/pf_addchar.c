/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_addchar.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/07 17:30:53 by pholster       #+#    #+#                */
/*   Updated: 2019/07/21 22:59:01 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void	pf_addchar(t_info *info, char c)
{
	pf_addtobuff(info, &c, 1);
}
