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

t_uint32	ft_set_rgba_intensity(
	t_uint32 rgba,
	float intensity
)
{
	t_color	color;

	//Todo prevent overflow
	color = ft_convert_rgba_to_color(rgba);
	color.r *= intensity;
	color.g *= intensity;
	color.b *= intensity;
	return (ft_convert_color_to_rgba(color));
}
