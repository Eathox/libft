/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_convert_color_to_rgba.c                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/16 15:19:27 by pholster      #+#    #+#                 */
/*   Updated: 2020/05/16 15:19:27 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

/*
** * Convert color struct to rgba byte data
*/
t_uint32	ft_convert_color_to_rgba(
	t_color const *color
)
{
	t_uint32	rgba;

	rgba = 0x0;
	rgba |= color->r << RGBA_RED_SHIFT;
	rgba |= color->g << RGBA_GREEN_SHIFT;
	rgba |= color->b << RGBA_BLUE_SHIFT;
	rgba |= color->a << RGBA_ALPHA_SHIFT;
	return (rgba);
}
