/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_count_if.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/08 15:28:35 by pholster       #+#    #+#                */
/*   Updated: 2019/07/23 14:13:45 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/typedefs.h"

size_t	ft_count_if(const char **str, t_bool (*f)(char *))
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	if (f == NULL || str == NULL)
		return (0);
	while (str[i] != NULL)
	{
		count += (f((char *)str[i]) == 1);
		i++;
	}
	return (count);
}
