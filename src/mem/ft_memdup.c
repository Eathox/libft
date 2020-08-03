/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/17 22:43:41 by pholster      #+#    #+#                 */
/*   Updated: 2019/08/21 20:41:40 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "ft/types.h"
#include "mem.h"

/*
** * Duplicates len amount of bytes from mem
** * Returns NULL if the allocation of the duplicate failed or if len is 0
*/
void		*ft_memdup(
	void const *mem,
	size_t len
) {
	void	*dup;

	if (len == 0)
		return (NULL);
	dup = malloc(len);
	if (dup == NULL)
		return (NULL);
	ft_memcpy(dup, mem, len);
	return (dup);
}
