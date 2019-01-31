/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_striter.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/10 11:03:33 by pholster       #+#    #+#                */
/*   Updated: 2019/01/31 17:53:51 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striter(char *s, void (*f)(char *))
{
	unsigned int	i;

	i = 0;
	if (f == NULL || s == NULL)
		return ;
	while (s[i] != '\0')
	{
		f(&s[i]);
		i++;
	}
}
