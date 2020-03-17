/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_del_serialize.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/03 19:34:04 by pholster       #+#    #+#                */
/*   Updated: 2020/03/03 19:34:04 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft/mem.h"

#include "serialize.h"

void	*ft_del_serialize(t_serialize **serialize)
{
	if (serialize == NULL || *serialize == NULL)
		return (NULL);
	ft_memdel((void**)&(*serialize)->content);
	ft_memdel((void**)serialize);
	return (NULL);
}
