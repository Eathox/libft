/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_putinfo.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/18 14:31:30 by pholster       #+#    #+#                */
/*   Updated: 2019/04/01 13:32:24 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	putflags(t_info *info)
{
	ft_putstr_fd("\nFlags:", PF_FD);
	ft_putstr_fd("\n Hash:\t\t", PF_FD);
	ft_putbool_fd(PF_FLAG_HASH, PF_FD);
	ft_putstr_fd("\n Zero:\t\t", PF_FD);
	ft_putbool_fd(PF_FLAG_ZERO, PF_FD);
	ft_putstr_fd("\n Min:\t\t", PF_FD);
	ft_putbool_fd(PF_FLAG_MIN, PF_FD);
	ft_putstr_fd("\n Plus:\t\t", PF_FD);
	ft_putbool_fd(PF_FLAG_PLUS, PF_FD);
	ft_putstr_fd("\n Space:\t\t", PF_FD);
	ft_putbool_fd(PF_FLAG_SPACE, PF_FD);
	ft_putstr_fd("\n Apostrophe:\t", PF_FD);
	ft_putbool_fd(PF_FLAG_APOST, PF_FD);
}

void		pf_putinfo(t_info *info)
{
	ft_putstr_fd("\nLength:\t\t", PF_FD);
	ft_putnbr_fd(PF_LENGTH, PF_FD);
	ft_putstr_fd("\nPrecision:\t", PF_FD);
	ft_putnbr_fd(PF_PRECISION, PF_FD);
	ft_putstr_fd("\nPrinted:\t", PF_FD);
	ft_putnbr_fd(PF_PRINTED, PF_FD);
	ft_putstr_fd("\nType:\t\t", PF_FD);
	ft_putnbr_fd(PF_TYPE, PF_FD);
	ft_putstr_fd("\nWidth:\t\t", PF_FD);
	ft_putnbr_fd(PF_WIDTH, PF_FD);
	putflags(info);
	ft_putstr_fd("\nVar_len:\t", PF_FD);
	ft_putnbr_fd(PF_VAR_LEN, PF_FD);
	ft_putstr_fd("\nVar_type:\t", PF_FD);
	ft_putnbr_fd(PF_VAR_TYPE, PF_FD);
	ft_putstr_fd("\nVar_base:\t", PF_FD);
	ft_putnbr_fd(PF_VAR_BASE, PF_FD);
	ft_putendl_fd("", PF_FD);
}
