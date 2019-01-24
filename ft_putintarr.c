/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putintarr.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/09 18:18:27 by pholster       #+#    #+#                */
/*   Updated: 2019/01/16 13:51:53 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putintarr(const int *tab, int len)
{
	int	i;

	i = 0;
	if (tab == NULL)
		return ;
	while (i < len)
	{
		ft_putnbr(tab[i++]);
		write(1, "\n", 1);
	}
}
