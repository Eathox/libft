/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_putwchar.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/20 16:42:53 by pholster       #+#    #+#                */
/*   Updated: 2019/04/01 13:28:03 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	pf_putwchar(t_info *info, t_wchar c)
{
	ft_pututf8_fd(c, PF_FD);
	PF_PRINTED += PF_VAR_LEN;
}
