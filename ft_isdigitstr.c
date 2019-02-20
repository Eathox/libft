/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isdigitstr.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/03 16:07:33 by pholster       #+#    #+#                */
/*   Updated: 2019/02/03 16:07:33 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isdigitstr(const char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (FALSE);
	while (str[i] != '\0')
	{
		if (str[i] < '0' && str[i] > '9')
			return (FALSE);
		i++;
	}
	return (TRUE);
}
