/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_getutf8strlen.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/29 12:27:39 by pholster       #+#    #+#                */
/*   Updated: 2019/04/01 13:28:03 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	pf_getutf8strlen(t_info *info)
{
	t_wchar	*str;
	int		n;

	str = PF_GVAR(t_wchar *);
	n = PF_PRECISION;
	if (str == NULL)
		PF_VAR_LEN = ft_constrain(6, 0, (n == -1) ? 6 : n);
	else if (n == -1)
		PF_VAR_LEN = ft_utf8strlen(str);
	else
		PF_VAR_LEN = ft_utf8strnlen(str, n);
}
