/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isbinary.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/04 15:01:34 by pholster      #+#    #+#                 */
/*   Updated: 2019/10/04 15:01:34 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "char.h"

/*
** * Checks if c is a base 2 number character
*/
bool		ft_isbinary(
	char c
) {
	return (c == '0' || c == '1');
}
