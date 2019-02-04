/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putpointer.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/04 00:11:56 by pholster       #+#    #+#                */
/*   Updated: 2019/02/04 09:30:17 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putpointer(void *pointer)
{
	char	*str;

	if (pointer == NULL)
		ft_putstr("(NULL)");
	str = ft_itoa_base((int)pointer, 16);
	if (str == NULL)
		return ;
	ft_putstr("0x");
	ft_putstr(str);
	ft_strdel(&str);
}
