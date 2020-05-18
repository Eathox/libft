/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   color.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/08 16:12:36 by pholster      #+#    #+#                 */
/*   Updated: 2019/08/21 23:46:14 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# include <string.h>
# include <stdlib.h>

# include "ft/types.h"

# define RGBA_RED_SHIFT 0
# define RGBA_GREEN_SHIFT 8
# define RGBA_BLUE_SHIFT 16
# define RGBA_ALPHA_SHIFT 24

# define RGBA_RED_MASK 0x000000FF
# define RGBA_GREEN_MASK 0x0000FF00
# define RGBA_BLUE_MASK 0x00FF0000
# define RGBA_ALPHA_MASK 0xFF000000

typedef	struct	s_color
{
	t_uint8	r;
	t_uint8	g;
	t_uint8	b;
	t_uint8	a;
}				t_color;

char			*ft_convert_color_to_hex(
	t_color const *color,
	bool include_alpha
);

t_uint32		ft_convert_color_to_rgba(
	t_color const *color
);

t_color			ft_mix_color(
	t_color const *bg,
	t_color const *fg
);

t_color			ft_scale_color_brightness(
	t_color const *color,
	float brightness
);

t_color			ft_convert_hex_to_color(
	char const *hex
);

t_uint32		ft_convert_hex_to_rgba(
	char const *hex
);

t_color			ft_convert_rgba_to_color(
	t_uint32 rgba
);

char			*ft_convert_rgba_to_hex(
	t_uint32 rgba,
	bool include_alpha
);

#endif
