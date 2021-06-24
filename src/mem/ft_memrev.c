/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memrev.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 10:18:13 by pholster      #+#    #+#                 */
/*   Updated: 2019/08/21 20:43:11 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../types/types.h"
#include "mem.h"

/*
** * Reveseres len amount of bytes in mem
** * Returns mem
*/
void *ft_memrev(
	void *mem,
	size_t len
) {
	uint8_t *mem_byte = mem;
	uint8_t temp;

	size_t i = 0;
	while (i < (len / 2)) {
		temp = mem_byte[i];
		mem_byte[i] = mem_byte[(len - 1) - i];
		mem_byte[(len - 1) - i] = temp;
		i++;
	}
	return (mem);
}
