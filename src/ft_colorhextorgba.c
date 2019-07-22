/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_colorhextorgba.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/17 14:59:08 by pholster       #+#    #+#                */
/*   Updated: 2019/07/21 22:45:17 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_color		*ft_colorhextorgba(t_color color)
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	unsigned char	a;
	t_color			*rgba;

	rgba = (t_color *)ft_memalloc(4);
	r = color;
	g = color >> 8;
	b = color >> 16;
	a = color >> 24;
	rgba[0] = r;
	rgba[1] = g;
	rgba[2] = b;
	rgba[3] = a;
	return (rgba);
}
