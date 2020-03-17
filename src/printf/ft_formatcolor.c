/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_formatcolor.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/18 14:24:33 by pholster       #+#    #+#                */
/*   Updated: 2019/08/21 21:26:32 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft/char.h"
#include "ft/str.h"
#include "ft/num.h"

#include "printf.h"
#include "priv.h"

static size_t	getrgb(const char *str, t_uint8 *rgb)
{
	size_t	i;
	size_t	totallen;
	size_t	len;

	i = 0;
	totallen = 0;
	while (i < 3)
	{
		len = ft_strislen(str, &ft_isdigit);
		if (len == 0)
			return (0);
		rgb[i] = ft_atoi(str);
		totallen += len;
		str += len + 1;
		if (*(str - 1) != ',' && i != 2)
			return (0);
		i++;
	}
	return (2 + totallen);
}

static size_t	addcolorrgb(t_info *info, t_bool bck, size_t len, t_uint8 *rgb)
{
	t_uint8	r;
	t_uint8	g;
	t_uint8	b;

	r = rgb[0];
	g = rgb[1];
	b = rgb[2];
	if (bck)
		ft_addrgbcolorbg(info, r, g, b);
	else
		ft_addrgbcolor(info, r, g, b);
	return (2 + len + bck);
}

static size_t	addcolor(t_info *info, t_bool bck, size_t len, int color)
{
	if (bck)
		ft_addcolorbg(info, color);
	else
		ft_addcolor(info, color);
	return (2 + len + bck);
}

size_t			ft_formatcolor(t_info *info, const char *str)
{
	t_uint8	rgb[3];
	char	*colorstr;
	int		color;
	size_t	len;
	t_bool	bck;

	bck = (*str == '!');
	color = ft_colorlcode(&str[bck]);
	len = ft_strislen(&str[bck], &ft_isdigit);
	if (str[bck] == '}')
	{
		(bck) ? ft_addcolorbg(info, -1) : ft_addcolor(info, -1);
		return (2 + bck);
	}
	if (len != 0 && str[bck + len] == '}')
		return (addcolor(info, bck, len, ft_atoi(&str[bck])));
	colorstr = ft_colorstr(color);
	len = (colorstr != NULL) ? ft_strlen(colorstr) : 0;
	ft_strdel(&colorstr);
	if (color != -1 && str[bck + len] == '}')
		return (addcolor(info, bck, len, color));
	len = getrgb(&str[bck], rgb);
	if (len != 0 && str[bck + len] == '}')
		return (addcolorrgb(info, bck, len, rgb));
	return (0);
}
