/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_addtobuff.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/15 22:58:40 by pholster       #+#    #+#                */
/*   Updated: 2019/07/21 22:59:01 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"
#include "../../includes/libft.h"
#include <unistd.h>

void		pf_addtobuff(t_info *info, char *str, size_t len)
{
	size_t	i;

	if (len + info->buff_len > PF_BUFF_SIZE)
	{
		i = PF_BUFF_SIZE - info->buff_len;
		ft_memcpy(&info->buff[info->buff_len], str, i);
		if (info->fd == -1)
			ft_lstaddbck(&info->buff_list, ft_lstnew(info->buff, PF_BUFF_SIZE));
		else
			write(info->fd, info->buff, PF_BUFF_SIZE);
		info->added += i;
		info->buff_len = 0;
		ft_bzero(info->buff, PF_BUFF_SIZE);
		pf_addtobuff(info, &str[i], len - i);
		return ;
	}
	ft_memcpy(&info->buff[info->buff_len], str, len);
	info->buff_len += len;
	info->added += len;
}
