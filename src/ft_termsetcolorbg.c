/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_termsetcolorbg.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/18 14:42:21 by pholster       #+#    #+#                */
/*   Updated: 2019/07/21 22:45:18 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_termsetcolorbg(t_color color)
{
	ft_termsetcolorbg_fd(color, 1);
}
