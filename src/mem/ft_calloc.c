/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 17:13:10 by pholster      #+#    #+#                 */
/*   Updated: 2019/08/21 21:12:11 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stdlib.h>

#include "mem.h"

/*
** * Allocates (size * count) amount of memory and sets it all to 0x0
** * Returns NULL if the allocation failed or if the given values would overflow
** * If size, count or both are 0 it also returns NULL
*/
void	*ft_calloc(
	size_t count,
	size_t size
) {
	void	*mem;
	size_t	final_size;

	if (count == 0 || size == 0)
		return (NULL);
	if (size > (SIZE_MAX / count))
		return (NULL);
	final_size = size * count;
	mem = malloc(final_size);
	if (mem == NULL)
		return (NULL);
	ft_bzero(mem, final_size);
	return (mem);
}
