/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_colorcode.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/18 16:13:28 by pholster       #+#    #+#                */
/*   Updated: 2019/03/18 16:28:39 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_colorcode(const char *str)
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
		if (ft_strequ_nocase(str, colors[i]))
			return (i);
		i++;
	}
	return (-1);
}
