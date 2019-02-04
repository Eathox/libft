/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putline_fd.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/09 15:26:35 by pholster       #+#    #+#                */
/*   Updated: 2019/02/04 11:21:46 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putline_fd(char *s, int fd)
{
	int		len;
	int		i;
	int		j;
	float	h;

	len = (int)ft_strlen(s);
	i = 0;
	j = 0;
	if (len > 80)
		return ;
	h = (80 - len) / 2;
	while (i != 80)
	{
		if (i < h || j == len)
			ft_putchar_fd('-', fd);
		else
		{
			ft_putchar_fd(s[j], fd);
			j++;
		}
		i++;
	}
	ft_putchar_fd('\n', fd);
}
