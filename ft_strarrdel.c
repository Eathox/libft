/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strarrdel.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/31 18:37:15 by pholster       #+#    #+#                */
/*   Updated: 2019/01/31 18:43:23 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strarrdel(char ***arr)
{
	int	i;

	i = 0;
	if (arr == NULL)
		return ;
	while ((*arr)[i] != 0)
	{
		ft_strdel(&(*arr)[i]);
		i++;
	}
	free(**arr);
	*arr = NULL;
}
