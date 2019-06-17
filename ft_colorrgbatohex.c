/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_colorrgbatohex.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/17 14:59:08 by pholster       #+#    #+#                */
/*   Updated: 2019/06/17 15:03:08 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_colorrgbatohex(char r, char g, char b, char a)
{
	int	color;

	color = r;
	color += g << 8;
	color += b << 16;
	color += a << 24;
	return (color);
}
