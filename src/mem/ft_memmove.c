/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 17:35:27 by pholster      #+#    #+#                 */
/*   Updated: 2019/08/21 20:41:40 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "mem.h"

/*
** * Copy len amount of bytes from src to dst memory area overlap is handled
** * Returns dst
*/
void	*ft_memmove(
	void *dst,
	void const *src,
	size_t len
) {
	if ((size_t)src < (size_t)dst)
		ft_memrcpy(dst, src, len);
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
