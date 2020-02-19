/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_del_tthread.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/07 16:57:18 by pholster       #+#    #+#                */
/*   Updated: 2020/02/07 16:57:18 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft/mem.h"

#include "ft/thpool.h"
#include "priv.h"

void	*ft_del_tthread(t_tthread **thread)
{
	if (thread == NULL || *thread == NULL)
		return (NULL);
	ft_memdel((void**)thread);
	return (NULL);
}
