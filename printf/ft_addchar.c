/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_addchar.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/07 17:30:53 by pholster       #+#    #+#                */
/*   Updated: 2019/08/21 20:42:50 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "priv.h"

void	ft_addchar(t_info *info, char c)
{
	ft_addtobuff(info, &c, 1);
}
