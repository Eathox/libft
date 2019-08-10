/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_striteri.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/10 11:18:33 by pholster       #+#    #+#                */
/*   Updated: 2019/07/23 14:25:03 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/typedefs.h"

void	ft_striteri(const char *str, void (*f)(size_t, char *))
{
	size_t	i;

	i = 0;
	if (f == NULL || str == NULL)
		return ;
	while (str[i] != '\0')
	{
		f(i, (char *)&str[i]);
		i++;
	}
}