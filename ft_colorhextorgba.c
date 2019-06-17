/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_colorhextorgba.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/17 14:59:08 by pholster       #+#    #+#                */
/*   Updated: 2019/06/17 15:28:58 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		*ft_colorhextorgba(int color)
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	unsigned char	a;
	int				*rgba;

	rgba = (int *)ft_memalloc(4);
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
