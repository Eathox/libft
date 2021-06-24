/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memdel.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 17:08:14 by pholster      #+#    #+#                 */
/*   Updated: 2019/08/21 21:12:47 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "mem.h"

/*
** * Frees the memory pointed to by *adr then sets *adr to NULL
** * If adr or *adr are NULL nothing happens
*/
void ft_memdel(
	void **adr
) {
	if (adr == NULL || *adr == NULL)
		return ;

	free(*adr);
	*adr = NULL;
}
