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

void	pf_putnutf8str(t_info *info, t_wchar *str, size_t n)
{
	ft_putnutf8str_fd(str, n, PF_FD);
	PF_PRINTED += n;
}
