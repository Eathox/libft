/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strclr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/09 13:58:39 by pholster       #+#    #+#                */
/*   Updated: 2019/02/25 13:11:09 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strclr(char *str)
{
	size_t	i;

	i = 0;
	if (str == NULL)
		return ;
	while (str[i] != '\0')
	{
		str[i] = '\0';
		i++;
	}
}
