/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_scale_color_brightness.c                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/16 15:09:22 by pholster      #+#    #+#                 */
/*   Updated: 2020/05/16 15:09:22 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>

#include "ft/num.h"

#include "color.h"

t_color	ft_scale_color_brightness(
	t_color const *color,
	float brightness
)
{
	t_color	result;

	result.r = ft_constrain((t_uint32)color->r * brightness, 0x0, UCHAR_MAX);
	result.g = ft_constrain((t_uint32)color->g * brightness, 0x0, UCHAR_MAX);
	result.b = ft_constrain((t_uint32)color->b * brightness, 0x0, UCHAR_MAX);
	result.a = color->a;
	return (result);
}
