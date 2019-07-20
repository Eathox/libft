/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_getwidth.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/04 17:50:26 by pholster       #+#    #+#                */
/*   Updated: 2019/07/20 21:13:26 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/libft.h"

size_t	pf_getwidth(t_info *info, const char *str)
{
	size_t	i;

	i = 1;
	if (*str == '*')
	{
		info->width = va_arg(info->args, int);
		if (info->width < 0)
		{
			PF_FLAG_MIN = TRUE;
			info->width = -info->width;
		}
		return (1);
	}
	info->width = ft_atoi(str);
	while (ft_isdigit(str[i]))
		i++;
	return (i);
}
