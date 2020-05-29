/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isupper.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/06 16:57:45 by pholster      #+#    #+#                 */
/*   Updated: 2019/08/21 21:04:36 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "char.h"

/*
** * Checks if c is a uppercase letter
*/
bool		ft_isupper(
	char c
)
{
	return (c >= 'A' && c <= 'Z');
}
