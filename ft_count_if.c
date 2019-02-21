/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_count_if.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/08 15:28:35 by pholster       #+#    #+#                */
/*   Updated: 2019/02/21 13:29:01 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_count_if(const char **str, int (*f)(char *))
{
	int				i;
	unsigned int	count;

	i = 0;
	count = 0;
	if (f == NULL || str == NULL)
		return (0);
	while (str[i] != NULL)
	{
		if (f((char *)str[i]) == 1)
			count++;
		i++;
	}
	return (count);
}
