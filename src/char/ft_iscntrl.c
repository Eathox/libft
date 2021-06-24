/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_iscntrl.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/09 11:42:00 by pholster      #+#    #+#                 */
/*   Updated: 2019/08/21 21:04:09 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "char.h"

/*
** * Checks if c is a control character
*/
bool ft_iscntrl(
	char c
) {
	return (c <= 31 || c == 127);
}
