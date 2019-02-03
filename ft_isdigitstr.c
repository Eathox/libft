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

int		ft_isdigitstr(const char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (FALSE);
	while (s[i] != '\0')
	{
		if (s[i] < '0' && s[i] > '9')
			return (FALSE);
		i++;
	}
	return (TRUE);
}
