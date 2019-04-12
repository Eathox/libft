/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_formatbackpad.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/07 14:15:04 by pholster       #+#    #+#                */
/*   Updated: 2019/04/01 13:28:03 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		pf_formatbackpad(t_info *info)
{
	char	*str;
	int		len;
	int		i;

	i = PF_PADADDED;
	len = ft_max(0, PF_WIDTH) - PF_VAR_LEN;
	if (PF_FLAG_MIN == FALSE)
		return ;
	str = ft_strnew(len);
	if (str == NULL)
		return ;
	while (i < len)
	{
		str[i] = ' ';
		i++;
	}
	pf_lstaddptr(info, str, i);
}
