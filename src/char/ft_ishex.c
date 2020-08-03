/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_ishex.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/04 15:01:34 by pholster      #+#    #+#                 */
/*   Updated: 2019/10/04 15:01:34 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "char.h"

/*
** * Checks if c is a base 16 number character, handles lower/upper case
*/
bool		ft_ishex(
	char c
) {
	c = ft_tolower(c);
	return (ft_isdigit(c) || (c >= 'a' && c <= 'f'));
}
