/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_chrdindex.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/03 22:38:37 by pholster       #+#    #+#                */
/*   Updated: 2019/02/25 13:06:41 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_chrdindex(const char *str, const char *dlm)
{
	size_t	i;
	int		dex;

	i = 0;
	if (str == NULL || dlm == NULL)
		return (-1);
	while (dlm[i] != '\0')
	{
		dex = ft_chrindex(str, dlm[i]);
		if (dex != -1)
			return (dex);
		i++;
	}
	return (-1);
}
