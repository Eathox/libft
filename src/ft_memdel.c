/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memdel.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 17:08:14 by pholster       #+#    #+#                */
/*   Updated: 2019/07/23 14:17:39 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/typedefs.h"

void	ft_memdel(void **ap)
{
	if (ap == NULL || *ap == NULL)
		return ;
	free(*ap);
	*ap = NULL;
}
