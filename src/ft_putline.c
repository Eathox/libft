/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putline.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/09 15:26:35 by pholster       #+#    #+#                */
/*   Updated: 2019/07/23 18:13:34 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_bool	ft_putline(const char *str)
{
	return (ft_putline_fd(str, 1));
}
