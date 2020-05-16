/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_del_tjob.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/07 16:41:22 by pholster      #+#    #+#                 */
/*   Updated: 2020/02/07 16:41:22 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft/mem.h"

#include "priv.h"

void		*ft_del_tjob(t_tjob **job, bool delete_task)
{
	if (job == NULL || *job == NULL)
		return (NULL);
	if (delete_task == true)
		ft_del_ttask(&(*job)->task);
	ft_memdel((void**)job);
	return (NULL);
}
