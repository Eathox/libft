/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_pututf8str_fd.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/20 12:01:12 by pholster       #+#    #+#                */
/*   Updated: 2019/07/21 22:45:18 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_pututf8str_fd(const t_wchar *str, int fd)
{
	size_t	i;

	i = 0;
	if (str == NULL)
	{
		ft_putstr_fd("(null)", fd);
		return ;
	}
	while (str[i] != '\0')
	{
		ft_pututf8_fd(str[i], fd);
		i++;
	}
}
