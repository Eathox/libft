/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isdigit.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/09 11:35:45 by pholster      #+#    #+#                 */
/*   Updated: 2019/08/21 21:04:14 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "char.h"

/*
** * Checks if c is a number
*/
bool		ft_isdigit(
	char c
) {
	return (c >= '0' && c <= '9');
}
