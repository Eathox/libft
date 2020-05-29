/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isspace.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/10 11:36:37 by pholster      #+#    #+#                 */
/*   Updated: 2019/08/21 20:40:44 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "char.h"

/*
** * Checks if c is any of the following: ' ', '\t', '\n', '\v', '\f' or '\r'
*/
bool		ft_isspace(
	char c
)
{
	return (c == ' ' || (c >= '\t' && c <= '\r'));
}
