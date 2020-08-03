/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_distribute.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/01 13:25:57 by pholster      #+#    #+#                 */
/*   Updated: 2019/08/21 20:42:50 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "priv.h"

size_t		ft_distribute(t_info *info, const char *start) {
	size_t	ret;

	if (*start == '{')
		ret = ft_formatcolor(info, &start[1]);
	else if (*start == '[')
		ret = ft_commands(info, &start[1]);
	else
	{
		ft_infosetdefault(info);
		ret = ft_getinfo(info, start);
		ft_formatdistribute(info);
	}
	return (ret);
}
