/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isascii.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/09 11:42:00 by pholster      #+#    #+#                 */
/*   Updated: 2019/08/21 21:04:09 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "char.h"

/*
** * Checks if c fits inside the ascii character set
*/
bool		ft_isascii(
	char c
) {
	return (c >= '\0');
}
