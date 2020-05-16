/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_convert_color_to_argb.c                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/16 15:19:27 by pholster      #+#    #+#                 */
/*   Updated: 2020/05/16 15:19:27 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

t_uint32	ft_convert_color_to_argb(
	t_color color
)
{
	t_uint32	argb;

	argb = (color.a << 24);
	argb = (color.r << 16) | argb;
	argb = (color.g << 8) | argb;
	argb = color.b | argb;
	return (argb);
}
