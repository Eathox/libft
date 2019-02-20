/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putline.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/09 15:26:35 by pholster       #+#    #+#                */
/*   Updated: 2019/02/04 11:22:01 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putline(const char *str)
{
	ft_putline_fd(str, 1);
}
