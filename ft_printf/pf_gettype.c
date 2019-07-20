/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_gettype.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/04 17:50:26 by pholster       #+#    #+#                */
/*   Updated: 2019/07/20 21:13:22 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/libft.h"

int		pf_gettype(t_info *info, const char *str)
{
	info->type = *str;
	if (ft_chrin(PF_A_TYPE_L, info->type))
	{
		info->type = ft_tolower(info->type);
		info->length = 'l';
	}
	return (-1);
}
