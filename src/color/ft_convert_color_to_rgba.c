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

t_uint32	ft_convert_color_to_rgba(
	t_color color
)
{
	t_uint32	rgba;

	rgba = color.r;
	rgba |= color.g << 8;
	rgba |= color.b << 16;
	rgba |= color.a << 24;
	return (rgba);
}
