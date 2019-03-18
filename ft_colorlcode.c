/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_colorlcode.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/18 16:13:28 by pholster       #+#    #+#                */
/*   Updated: 2019/03/18 17:21:24 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_colorlcode(const char *str)
{
	char	*colors[16];
	int		i;

	i = 0;
	ft_strarrset(colors, 16, "black", "red", "green", "yellow", "blue", \
		"magenta", "cyan", "white", "bright black", "bright red", \
		"bright green", "bright yellow", "bright blue", "bright magenta", \
		"bright cyan", "bright white");
	while (i < 15)
	{
		if (ft_strnequ_nocase(str, colors[i], ft_strlen(colors[i])))
			return (i);
		i++;
	}
	return (-1);
}
