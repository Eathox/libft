/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrev.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 10:18:13 by pholster       #+#    #+#                */
/*   Updated: 2019/02/06 16:53:26 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strrev(char *s)
{
	int	i;
	int a;
	int	len;

	i = 0;
	if (s == NULL)
		return ;
	len = (int)ft_strlen(s);
	while (i < (len / 2))
	{
		a = s[i];
		s[i] = s[(len - 1) - i];
		s[(len - 1) - i] = a;
		i++;
	}
}
