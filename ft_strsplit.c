/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strsplit.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 15:22:38 by pholster       #+#    #+#                */
/*   Updated: 2019/02/04 10:17:35 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_strsplit(const char *str, char c)
{
	char	**arr;
	char	*cs;

	cs = ft_chrtostr(c);
	if (cs == NULL)
		return (NULL);
	arr = ft_strdsplit(str, &c);
	ft_strdel(&cs);
	return (arr);
}
