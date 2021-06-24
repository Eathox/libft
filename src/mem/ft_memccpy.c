/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memccpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 16:56:29 by pholster      #+#    #+#                 */
/*   Updated: 2019/08/21 21:12:30 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

#include "../types/types.h"
#include "mem.h"

/*
** * Copy at most len amount of bytes in order of front to back from src to dst
** * Stoping when c is found in src
** * This function does not handle memory area overlap
** * Returns a pointer to the next byte in dst after c or NULL if c wasent found
*/
void *ft_memccpy(
	void *dst,
	void const *src,
	t_uint8 c,
	size_t len
) {
	t_uint8 const *src_byte = src;
	t_uint8 *dst_byte = dst;

	size_t i = 0;
	while (i < len) {
		dst_byte[i] = src_byte[i];
		if (src_byte[i] == c)
			return (&dst_byte[i + 1]);
		i++;
	}
	return (NULL);
}
