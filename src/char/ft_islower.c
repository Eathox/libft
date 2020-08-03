/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_islower.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/06 16:57:43 by pholster      #+#    #+#                 */
/*   Updated: 2019/08/21 21:04:19 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "char.h"

/*
** * Checks if c is a lowercase letter
*/
bool		ft_islower(
	char c
) {
	return (c >= 'a' && c <= 'z');
}
