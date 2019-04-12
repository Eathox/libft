/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_putnutf8str.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/20 16:50:11 by pholster       #+#    #+#                */
/*   Updated: 2019/04/01 13:28:03 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	pf_addwcharstr(t_info *info, t_wchar *str, size_t n)
{
	size_t	i;
	size_t	bytes;
	size_t	len;

	i = 0;
	len = 0;
	if (n == 0)
		return ;
	if (str == NULL)
	{
		pf_addnstr(info, "(null)", n);
		return ;
	}
	while (str[i] != '\0')
	{
		bytes = ft_utf8len(str[i]);
		if ((len + bytes) > n)
			return ;
		len += bytes;
		pf_addwchar(info, str[i]);
		i++;
	}
}
