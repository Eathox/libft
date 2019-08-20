/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strsplit.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 15:22:38 by pholster       #+#    #+#                */
/*   Updated: 2019/08/20 13:49:30 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_strsplit(char *str, char c)
{
	char	**arr;
	char	*cs;

	cs = ft_chrtostr(c);
	if (cs == NULL)
		return (NULL);
	arr = ft_strdsplit(str, cs);
	ft_strdel(&cs);
	return (arr);
}
