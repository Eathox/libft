/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isblank.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/30 00:14:15 by pholster      #+#    #+#                 */
/*   Updated: 2019/08/21 21:04:12 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "char.h"

/*
** * Checks if c is a space or tab
*/
bool		ft_isblank(
	char c
) {
	return (c == ' ' || c == '\t');
}
