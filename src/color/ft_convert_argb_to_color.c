/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_convert_argb_to_color.c                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/16 15:17:37 by pholster      #+#    #+#                 */
/*   Updated: 2020/05/16 15:17:37 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

t_color	ft_convert_argb_to_color(
	t_uint32 argb
)
{
	t_color	color;

	color.a = (t_uint8)(argb >> 24);
	color.r = (t_uint8)(argb >> 16);
	color.g = (t_uint8)(argb >> 8);
	color.b = (t_uint8)argb;
	return (color);
}
