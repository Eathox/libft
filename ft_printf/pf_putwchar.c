/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_putwchar.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/20 16:42:53 by pholster       #+#    #+#                */
/*   Updated: 2019/03/31 12:42:32 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_putwchar(t_info *info, t_wchar c)
{
	ft_pututf8(c);
	PF_PRINTED += PF_VAR_LEN;
}
