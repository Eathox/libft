/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_colorrgbatohex.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/17 14:59:08 by pholster       #+#    #+#                */
/*   Updated: 2019/07/14 11:59:41 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

t_color		ft_colorrgbatohex(char r, char g, char b, char a)
{
	t_color	color;

	color = r;
	color |= ((long long)g << 8);
	color |= ((long long)b << 16);
	color |= ((long long)a << 24);
	return (color);
}
