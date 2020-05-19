/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_bzero.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 16:47:44 by pholster      #+#    #+#                 */
/*   Updated: 2019/08/21 20:41:40 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "mem.h"

/*
** * Sets len amount of bytes to the value 0x0 in the memory mem
*/
void	ft_bzero(void *mem, size_t len)
{
	if (len != 0)
		ft_memset(mem, 0x0, len);
}
