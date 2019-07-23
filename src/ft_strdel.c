/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdel.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/10 10:56:03 by pholster       #+#    #+#                */
/*   Updated: 2019/07/23 14:24:27 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/typedefs.h"

void	ft_strdel(char **as)
{
	if (as == NULL || *as == NULL)
		return ;
	free(*as);
	*as = NULL;
}
