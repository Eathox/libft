/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_putinfo.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/18 14:31:30 by pholster       #+#    #+#                */
/*   Updated: 2019/03/31 12:42:32 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	putflags(t_info *info)
{
	ft_putstr("\nFlags:");
	ft_putstr("\n Hash:\t\t");
	ft_putbool(PF_FLAG_HASH);
	ft_putstr("\n Zero:\t\t");
	ft_putbool(PF_FLAG_ZERO);
	ft_putstr("\n Min:\t\t");
	ft_putbool(PF_FLAG_MIN);
	ft_putstr("\n Plus:\t\t");
	ft_putbool(PF_FLAG_PLUS);
	ft_putstr("\n Space:\t\t");
	ft_putbool(PF_FLAG_SPACE);
	ft_putstr("\n Apostrophe:\t");
	ft_putbool(PF_FLAG_APOST);
}

void		pf_putinfo(t_info *info)
{
	ft_putstr("\nLength:\t\t");
	ft_putnbr(PF_LENGTH);
	ft_putstr("\nPrecision:\t");
	ft_putnbr(PF_PRECISION);
	ft_putstr("\nPrinted:\t");
	ft_putnbr(PF_PRINTED);
	ft_putstr("\nType:\t\t");
	ft_putnbr(PF_TYPE);
	ft_putstr("\nWidth:\t\t");
	ft_putnbr(PF_WIDTH);
	putflags(info);
	ft_putstr("\nVar_len:\t");
	ft_putnbr(PF_VAR_LEN);
	ft_putstr("\nVar_type:\t");
	ft_putnbr(PF_VAR_TYPE);
	ft_putstr("\nVar_base:\t");
	ft_putnbr(PF_VAR_BASE);
	ft_putendl("");
}
