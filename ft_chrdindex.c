/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_chrdindex.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/03 22:38:37 by pholster       #+#    #+#                */
/*   Updated: 2019/02/21 14:01:23 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_chrdindex(const char *str, const char *delims)
{
	unsigned int	i;
	int				dex;

	i = 0;
	if (str == NULL || delims == NULL)
		return (-1);
	while (delims[i] != '\0')
	{
		dex = ft_chrindex(str, delims[i]);
		if (dex != -1)
			return (dex);
		i++;
	}
	return (-1);
}
