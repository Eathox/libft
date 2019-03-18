/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_colorncode.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/18 16:13:28 by pholster       #+#    #+#                */
/*   Updated: 2019/03/18 17:26:29 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_colorncode(const char *str, size_t n)
{
	char	*colors[16];
	size_t	i;

	i = 0;
	if (n > 15)
		n = 15;
	ft_strarrset(colors, 16, "black", "red", "green", "yellow", "blue", \
		"magenta", "cyan", "white", "bright black", "bright red", \
		"bright green", "bright yellow", "bright blue", "bright magenta", \
		"bright cyan", "bright white");
	while (i < n)
	{
		if (ft_strequ_nocase(str, colors[i]))
			return ((int)i);
		i++;
	}
	return (-1);
}
