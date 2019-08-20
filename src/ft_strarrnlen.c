/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strarrnlen.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/07 16:33:10 by pholster       #+#    #+#                */
/*   Updated: 2019/08/20 13:49:30 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "typedefs.h"

size_t	ft_strarrnlen(char **arr, size_t n)
{
	size_t	len;

	len = 0;
	while (len < n && arr[len] != NULL)
		len++;
	return (len);
}
