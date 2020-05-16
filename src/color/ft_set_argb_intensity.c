/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_set_argb_intensity.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/16 15:09:22 by pholster      #+#    #+#                 */
/*   Updated: 2020/05/16 15:09:22 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

t_uint32	ft_set_argb_intensity(
	t_uint32 argb,
	float intensity
)
{
	t_color	color;

	color = ft_convert_argb_to_color(argb);
	color.r *= intensity;
	color.g *= intensity;
	color.b *= intensity;
	return (ft_convert_color_to_argb(color));
}
