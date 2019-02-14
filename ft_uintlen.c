/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_uintlen.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/03 14:52:39 by pholster       #+#    #+#                */
/*   Updated: 2019/02/14 15:44:17 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_uintlen(unsigned int value)
{
	return (ft_uintlen_base(value, 10));
}
