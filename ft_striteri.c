/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_striteri.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/10 11:18:33 by pholster       #+#    #+#                */
/*   Updated: 2019/02/25 13:11:58 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(const char *str, void (*f)(unsigned int, char *))
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
