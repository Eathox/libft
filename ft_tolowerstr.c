/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_tolowerstr.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/09 12:20:29 by pholster       #+#    #+#                */
/*   Updated: 2019/01/31 17:56:45 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_tolowerstr(char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
		return ;
	while (s[i] != '\0')
	{
		if (s[i] >= 'A' && s[i] <= 'Z')
			s[i] = s[i] + 32;
		i++;
	}
}
