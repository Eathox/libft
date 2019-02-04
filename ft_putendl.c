/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putendl.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/09 12:02:20 by pholster       #+#    #+#                */
/*   Updated: 2019/02/02 17:19:47 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl(const char *s)
{
	if (s == NULL)
	{
		ft_putendl("(NULL)");
		return ;
	}
	ft_putstr(s);
	write(1, "\n", 1);
}
