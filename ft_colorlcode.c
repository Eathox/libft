/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_colorlcode.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/18 16:13:28 by pholster       #+#    #+#                */
/*   Updated: 2019/05/01 01:33:58 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_colorlcode(const char *str)
{
	char	**ret;
	char	**colors;
	size_t	i;

	i = 0;
	colors = ft_strarrnew(16);
	if (colors == NULL)
		return (-1);
	ret = ft_strarrcpy_var(colors, 16, "black", "red", "green", "yellow", \
		"blue", "magenta", "cyan", "white", "bright black", "bright red", \
		"bright green", "bright yellow", "bright blue", "bright magenta", \
		"bright cyan", "bright white");
	while (ret != NULL && i < 16)
	{
		if (ft_strnequ_nocase(str, colors[i], ft_strlen(colors[i])))
		{
			ft_strarrdel(&colors);
			return ((int)i);
		}
		i++;
	}
	ft_strarrdel(&colors);
	return (-1);
}
