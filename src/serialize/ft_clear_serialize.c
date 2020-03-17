/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_clear_serialize.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/04 00:00:48 by pholster       #+#    #+#                */
/*   Updated: 2020/03/04 00:00:48 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft/mem.h"

#include "serialize.h"

#include "priv.h"

void	ft_clear_serialize(t_serialize *serialize)
{
	ft_memdel((void**)&serialize->content);
	serialize->content_allocated_size = 0;
	serialize->content_size = 0;
}
