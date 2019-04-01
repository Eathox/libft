/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_getstrlen.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/29 12:27:39 by pholster       #+#    #+#                */
/*   Updated: 2019/04/01 13:28:03 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	pf_getstrlen(t_info *info)
{
	char	*str;
	int		n;

	str = PF_GVAR(char *);
	n = PF_PRECISION;
	if (str == NULL)
		PF_VAR_LEN = ft_constrain(6, 0, (n == -1) ? 6 : n);
	else if (n == -1)
		PF_VAR_LEN = ft_strlen(str);
	else
		PF_VAR_LEN = ft_strnlen(str, n);
}
