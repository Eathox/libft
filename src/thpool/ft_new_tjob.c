/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_new_tjob.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/07 16:40:19 by pholster      #+#    #+#                 */
/*   Updated: 2020/02/07 16:40:19 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft/mem.h"

#include "thpool.h"
#include "priv.h"

t_tjob	*ft_new_tjob(t_ttask *task)
{
	t_tjob	*job;

	job = ft_memalloc(sizeof(t_tjob));
	if (job == NULL)
		return (NULL);
	job->task = task;
	return (job);
}
