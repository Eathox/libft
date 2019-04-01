/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_setcolor.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/18 14:24:33 by pholster       #+#    #+#                */
/*   Updated: 2019/04/01 13:28:03 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	getrgb(const char *str, int *rgb)
{
	int		i;
	int		totallen;
	int		len;

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

static int	setcolorrgb(int bck, int len, int *rgb, int fd)
{
	int		r;
	int		g;
	int		b;

	r = rgb[0];
	g = rgb[1];
	b = rgb[2];
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		return (0);
	if (bck)
		ft_termsetrgbcolorbg_fd(r, g, b, fd);
	else
		ft_termsetrgbcolor_fd(r, g, b, fd);
	return (2 + len + bck);
}

static int	setcolor(int bck, int len, int color, int fd)
{
	if (color < 0 || color > 255)
		return (0);
	if (bck)
		ft_termsetcolorbg_fd(color, fd);
	else
		ft_termsetcolor_fd(color, fd);
	return (2 + len + bck);
}

int			pf_setcolor(t_info *info, const char *str)
{
	int		rgb[3];
	char	*colorstr;
	int		color;
	int		len;
	int		bck;

	bck = (*str == '!');
	color = ft_colorlcode(&str[bck]);
	len = ft_strislen(&str[bck], &ft_isdigit);
	if (str[bck] == '}')
	{
		(bck) ? ft_termresetcolorbg_fd(PF_FD) : ft_termresetcolor_fd(PF_FD);
		return (2 + bck);
	}
	if (len != 0 && str[bck + len] == '}')
		return (setcolor(bck, len, ft_atoi(&str[bck]), PF_FD));
	colorstr = ft_colorstr(color);
	len = (colorstr != NULL) ? ft_strlen(colorstr) : 0;
	ft_strdel(&colorstr);
	if (color != -1 && str[bck + len] == '}')
		return (setcolor(bck, len, color, PF_FD));
	len = getrgb(&str[bck], rgb);
	if (len != 0 && str[bck + len] == '}')
		return (setcolorrgb(bck, len, rgb, PF_FD));
	return (0);
}
