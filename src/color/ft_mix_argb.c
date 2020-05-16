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

t_uint32	ft_mix_argb(
	t_uint32 argb_dst,
	t_uint32 argb_src
)
{
	float			alpha;
	t_color			color_dst;
	t_color			color_src;

	color_dst = ft_convert_argb_to_color(argb_dst);
	color_src = ft_convert_argb_to_color(argb_src);
	alpha = (float)color_src.a / UCHAR_MAX;
	if (alpha == 0)
		return (argb_dst);
	color_dst.a -= (color_dst.a - color_src.a) * alpha;
	color_dst.r = color_dst.r * (1 - alpha) + color_src.r * alpha;
	color_dst.g = color_dst.g * (1 - alpha) + color_src.g * alpha;
	color_dst.b = color_dst.b * (1 - alpha) + color_src.b * alpha;
	return (ft_convert_color_to_argb(color_dst));
}
