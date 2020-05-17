/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_mix_color.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/16 15:09:17 by pholster      #+#    #+#                 */
/*   Updated: 2020/05/16 15:09:17 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>

#include "color.h"

t_color		ft_mix_color(
	t_color const *bg,
	t_color const *fg
)
{
	float	alpha;
	t_color	result;

	//Todo looking to rgba mixing algorithms
	alpha = (float)fg->a / UCHAR_MAX;
	if (alpha == 0)
		return (*bg);
	if (alpha == 1)
		return (*fg);
	result.r = bg->r * (1 - alpha) + fg->r * alpha;
	result.g = bg->g * (1 - alpha) + fg->g * alpha;
	result.b = bg->b * (1 - alpha) + fg->b * alpha;
	result.a = bg->a - (bg->a - fg->a) * alpha;
	return (result);
}
