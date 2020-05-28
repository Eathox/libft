/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_toupper.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/09 11:53:23 by pholster      #+#    #+#                 */
/*   Updated: 2019/07/23 14:28:24 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "char.h"

/*
** * If c is an lowercase letter return its uppercase equivalent
*/
char		ft_toupper(
	char c
)
{
	if (c >= 'a' && c <= 'z')
		c -= ('a' - 'A');
	return (c);
}
