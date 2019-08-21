/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_gettype.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/04 17:50:26 by pholster       #+#    #+#                */
/*   Updated: 2019/08/21 16:56:06 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft.h"

int		pf_gettype(t_info *info, char *str)
{
	info->type = *str;
	if (ft_chrin(PF_A_TYPE_L, info->type))
	{
		info->type = ft_tolower(info->type);
		info->length = 'l';
	}
	return (-1);
}
