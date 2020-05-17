/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_mix_argb.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/16 15:09:17 by pholster      #+#    #+#                 */
/*   Updated: 2020/05/16 15:09:17 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>

#include "color.h"

t_uint32	ft_mix_rgba(
	t_uint32 rgba_dst,
	t_uint32 rgba_src
)
{
	float			alpha;
	t_color			color_dst;
	t_color			color_src;

	//Todo prevent overflow
	color_dst = ft_convert_rgba_to_color(rgba_dst);
	color_src = ft_convert_rgba_to_color(rgba_src);
	alpha = (float)color_src.a / UCHAR_MAX;
	if (alpha == 0)
		return (rgba_dst);
	color_dst.a -= (color_dst.a - color_src.a) * alpha;
	color_dst.r = color_dst.r * (1 - alpha) + color_src.r * alpha;
	color_dst.g = color_dst.g * (1 - alpha) + color_src.g * alpha;
	color_dst.b = color_dst.b * (1 - alpha) + color_src.b * alpha;
	return (ft_convert_color_to_rgba(color_dst));
}
