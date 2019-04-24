/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_addtobuff.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/15 22:58:40 by pholster       #+#    #+#                */
/*   Updated: 2019/04/24 14:29:55 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

//FIX THE JOIN FUNCTION TO USE A LIST INSTEAD OF BUFFER

static void	join(t_info *info, char *str, size_t len)
{
	char	*temp;

	if (len + (PF_BUFF_LEN % PF_BUFF_SIZE) > PF_BUFF_SIZE)
	{
		temp = ft_strnew(PF_BUFF_LEN + PF_BUFF_SIZE);
		ft_memcpy(temp, PF_BUFF, PF_BUFF_LEN);
		free(PF_BUFF);
		PF_BUFF = temp;
	}
	ft_memcpy(&PF_BUFF[PF_BUFF_LEN], str, len);
	PF_BUFF_LEN += len;
	PF_ADDED += len;
}

void		pf_addtobuff(t_info *info, char *str, size_t len)
{
	size_t	i;

	if (PF_FD == -1)
	{
		join(info, str, len);
		return ;
	}
	if (len + PF_BUFF_LEN > PF_BUFF_SIZE)
	{
		i = PF_BUFF_SIZE - PF_BUFF_LEN;
		ft_memcpy(&PF_BUFF[PF_BUFF_LEN], str, i);
		write(PF_FD, PF_BUFF, PF_BUFF_SIZE);
		ft_bzero(PF_BUFF, PF_BUFF_SIZE);
		ft_memcpy(PF_BUFF, &str[i], len - i);
		PF_BUFF_LEN = len - i;
	}
	else
	{
		ft_memcpy(&PF_BUFF[PF_BUFF_LEN], str, len);
		PF_BUFF_LEN += len;
	}
	PF_ADDED += len;
}
