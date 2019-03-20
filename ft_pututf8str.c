/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_pututf8str.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/20 12:01:12 by pholster       #+#    #+#                */
/*   Updated: 2019/03/20 17:51:05 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_pututf8str(t_wchar *str)
{
	size_t	i;

	i = 0;
	if (str == NULL)
	{
		ft_putstr("(null)");
		return ;
	}
	while (str[i] != '\0')
	{
		ft_pututf8(str[i]);
		i++;
	}
}
