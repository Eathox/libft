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

void	ft_putline_fd(const char *str, int fd)
{
	int		len;
	int		i;
	int		j;
	float	half;

	len = (int)ft_strlen(str);
	i = 0;
	j = 0;
	if (len > 80)
		return ;
	half = (80 - len) / 2;
	while (i != 80)
	{
		if (i < half || j == len)
			ft_putchar_fd('-', fd);
		else
		{
			ft_putchar_fd(str[j], fd);
			j++;
		}
		i++;
	}
	ft_putchar_fd('\n', fd);
}
