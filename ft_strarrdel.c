/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strarrdel.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/31 18:37:15 by pholster       #+#    #+#                */
/*   Updated: 2019/02/25 13:10:49 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strarrdel(char ***arr)
{
	size_t	i;

	i = 0;
	if (arr == NULL || *arr == NULL)
		return ;
	while ((*arr)[i] != NULL)
	{
		ft_strdel(&(*arr)[i]);
		i++;
	}
	free(*arr);
	*arr = NULL;
}
