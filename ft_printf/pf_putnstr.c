/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_putnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/07 17:30:53 by pholster       #+#    #+#                */
/*   Updated: 2019/04/01 12:47:04 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_putnstr(t_info *info, char *str, size_t n)
{
	ft_putnstr_fd(str, n, PF_FD);
	PF_PRINTED += n;
}
