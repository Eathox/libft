/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memalloc.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 17:13:10 by pholster      #+#    #+#                 */
/*   Updated: 2019/08/21 21:12:11 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "mem.h"

/*
** * Allocates size amount of memory and sets it all to 0x0
** * Returns NULL if the allocation failed or if size is 0
*/
void	*ft_memalloc(
	size_t size
) {
	return (ft_calloc(1, size));
}
