/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstmemdel.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/13 15:09:24 by pholster       #+#    #+#                */
/*   Updated: 2019/02/06 03:35:49 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstmemdel(void *content, size_t size)
{
	(void)size;
	ft_memdel(&content);
}
