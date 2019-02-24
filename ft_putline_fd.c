/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putline_fd.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/09 15:26:35 by pholster       #+#    #+#                */
/*   Updated: 2019/02/24 14:50:51 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putline_fd(const char *str, int fd)
{
	size_t	i;
	size_t	j;
	size_t	len;
	size_t	half;

	i = 0;
	j = 0;
	len = ft_strnlen(str, 81);
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
