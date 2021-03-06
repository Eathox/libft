/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isprint.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/09 11:43:50 by pholster      #+#    #+#                 */
/*   Updated: 2019/08/21 21:04:25 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "char.h"

/*
** * Checks if c is a printable character including space
*/
bool		ft_isprint(
	char c
) {
	return (c >= ' ' && c <= '~');
}
