/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_putchar.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/07 17:30:53 by pholster       #+#    #+#                */
/*   Updated: 2019/04/01 13:28:03 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	pf_putchar(t_info *info, char c)
{
	ft_putchar_fd(c, PF_FD);
	PF_PRINTED++;
}
