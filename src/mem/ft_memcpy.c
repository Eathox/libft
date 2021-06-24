/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 16:56:29 by pholster      #+#    #+#                 */
/*   Updated: 2019/08/21 21:12:30 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../types/types.h"
#include "mem.h"

/*
** * Copy len amount of bytes in order of front to back from src to dst
** * This function does not handle memory area overlap use ft_memmove instead
** * Returns dst
*/
void *ft_memcpy(
	void *dst,
	const void *src,
	size_t len
) {
	t_uint8 const *src_byte = src;
	t_uint8 *dst_byte = dst;

	size_t i = 0;
	while (i < len) {
		dst_byte[i] = src_byte[i];
		i++;
	}
	return (dst);
}
