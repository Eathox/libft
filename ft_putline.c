/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putline.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/09 15:26:35 by pholster       #+#    #+#                */
/*   Updated: 2019/01/31 17:50:54 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putline(char *s)
{
	int		len;
	int		i;
	int		j;
	float	h;

	len = ft_strlen(s);
	i = 0;
	j = 0;
	if (len > 80)
		return ;
	h = (80 - len) / 2;
	while (i != 80)
	{
		if (i < h || j == len)
			ft_putchar('-');
		else
		{
			ft_putchar(s[j]);
			j++;
		}
		i++;
	}
	ft_putchar('\n');
}
