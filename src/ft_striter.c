/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_striter.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/10 11:03:33 by pholster       #+#    #+#                */
/*   Updated: 2019/08/20 13:49:30 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "typedefs.h"

void	ft_striter(char *str, void (*f)(char *))
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		f((char *)&str[i]);
		i++;
	}
}
