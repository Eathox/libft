/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strclr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/09 13:58:39 by pholster       #+#    #+#                */
/*   Updated: 2019/01/31 17:53:08 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strclr(char *s)
{
	unsigned int	i;

	i = 0;
	if (s == NULL)
		return ;
	while (s[i] != '\0')
	{
		s[i] = '\0';
		i++;
	}
}
