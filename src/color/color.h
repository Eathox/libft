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

/*
** * Convert color struct to hex string data
** * Returns NULL if the allocation of the hex string failed
*/
char			*ft_convert_color_to_hex(
	t_color const *color,
	bool include_alpha
);

/*
** * Convert color struct to rgba byte data
*/
t_uint32		ft_convert_color_to_rgba(
	t_color const *color
);

/*
** * Mix 2 color structs together resulting in a new color struct
*/
t_color			ft_mix_color(
	t_color const *bg,
	t_color const *fg
);

/*
** * Scale color struct brightness, doesn't affect alpha channel
** * Protected againts overflow doesn't perserve color at max and min brightness
*/
t_color			ft_scale_color_brightness(
	t_color const *color,
	float brightness
);

/*
** * Convert hex string data to color struct
** * Supports 6 and 8 character long hex strings
*/
t_color			ft_convert_hex_to_color(
	char const *hex
);

/*
** * Convert hex string data to rgba byte data
** * Supports 6 and 8 character long hex strings
*/
t_uint32		ft_convert_hex_to_rgba(
	char const *hex
);

/*
** * Convert rgba byte data to color struct
*/
t_color			ft_convert_rgba_to_color(
	t_uint32 rgba
);

/*
** * Convert rgba byte data to hex string data
** * Returns NULL if the allocation of the hex string failed
*/
char			*ft_convert_rgba_to_hex(
	t_uint32 rgba,
	bool include_alpha
);

#endif
