/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_colorrgbatohex.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/17 14:59:08 by pholster       #+#    #+#                */
/*   Updated: 2019/07/23 14:13:26 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/typedefs.h"

t_color		ft_colorrgbatohex(t_color r, t_color g, t_color b, t_color a)
{
	t_color	color;

	color = r;
	color |= ((long long)g << 8);
	color |= ((long long)b << 16);
	color |= ((long long)a << 24);
	return (color);
}
