/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putunum.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/08 15:28:35 by pholster       #+#    #+#                */
/*   Updated: 2019/07/21 22:45:17 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_putunum(uintmax_t value)
{
	ft_putunum_cbase_fd(value, 10, TRUE, 1);
}
