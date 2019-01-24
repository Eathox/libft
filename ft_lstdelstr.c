/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstdelstr.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/13 15:09:24 by pholster       #+#    #+#                */
/*   Updated: 2019/01/14 20:20:02 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelstr(void *s, size_t size)
{
	if (s == NULL)
		return ;
	(void)size;
	ft_strdel((char **)&s);
}
