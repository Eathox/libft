#include <limits.h>

#include "ft/num.h"
#include "color.h"

/*
** * Scale color struct brightness, doesn't affect alpha channel
** * Protected againts overflow doesn't perserve color at max and min brightness
*/
t_color	ft_scale_color_brightness(
	t_color const *color,
	float brightness
) {
	t_color	result;

	result.r = ft_constrain((t_uint32)(color->r * brightness), 0x0, UCHAR_MAX);
	result.g = ft_constrain((t_uint32)(color->g * brightness), 0x0, UCHAR_MAX);
	result.b = ft_constrain((t_uint32)(color->b * brightness), 0x0, UCHAR_MAX);
	result.a = color->a;
	return (result);
}
