/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_striteri.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/10 11:18:33 by pholster       #+#    #+#                */
/*   Updated: 2019/08/20 13:49:30 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "typedefs.h"

void	ft_striteri(char *str, void (*f)(size_t, char *))
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		f(i, (char *)&str[i]);
		i++;
	}
}
